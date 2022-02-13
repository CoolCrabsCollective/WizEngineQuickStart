cmake_minimum_required(VERSION 3.7)

get_filename_component(PARENT_PROJECT_PATH .. ABSOLUTE)
get_filename_component(PARENT_PROJECT_NAME ${PARENT_PROJECT_PATH} NAME)

project(${PARENT_PROJECT_NAME}_client)

set(WizEngine_COMMIT bdc51efc27c842d69592c2488780b3b01e829e51)

if(CMAKE_COMPILER_IS_GNUCXX AND NOT WIN32)
    # Not for windows because windres.exe doesn't support those
    add_definitions(-Wall -ansi -Wno-deprecated -pthread -Wpedantic)
endif()

if(WIN32)
    # static linking of important libraries on windows
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ -lwsock32 -lws2_32 ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,--whole-archive -lpthread -Wl,--no-whole-archive")
    add_compile_definitions(OS_WINDOWS) # applies C++ macro
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    add_compile_definitions(OS_MAC) # applies C++ macro
elseif(UNIX)
    # static linking of libraries on linux
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath,./lib/") # -lpthread -lFLAC -logg -lvorbis -lvorbisfile -lvorbisenc -lc -lm -lfreetype -lopenal -ldl -lX11 -lXrandr -lXcursor -lGL -ludev -lrt -lz -lbz2 -lpng -lharfbuzz -lbrotlidec -lstdc++ -lgcc -lxcb -lXext -lXrender -lXfixes -lGLdispatch -lGLX -lgraphite2 -lglib -lbrotlicommon -lXau -lXdmcp -lpcre")

    add_compile_definitions(OS_UNIX) # applies C++ macro
endif()

# Note: os_finder.h ensures OS_SWITCH is defined when no other OS is defined


#
# Set C++ version
#
set(CMAKE_CXX_STANDARD 20)


#
# The following if-else chain makes the different platform output at different
# paths:
#
# out/
#   windows64/
#   windows32/
#   mac/
#   linux64/
#   linux32/
#   switch/ (handled by Makefile)
#
if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/windows64/)
    else()
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/windows32/)
    endif()
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/mac/)
elseif(UNIX)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux64/lib/)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux64/)
    else()
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux32/lib/)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux32/)
    endif()
endif()

# Fetches SFML dependency and loads its CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
        SFML
        URL https://github.com/SFML/SFML/archive/ef8d6ee7f710fff9bdaf69c6bb3660fa4d3a8958.zip
)
FetchContent_MakeAvailable(SFML)

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
FetchContent_GetProperties(SFML)

FetchContent_Declare(
        WizEngine
	    URL https://github.com/WheezyWiseWizards/WizEngine/archive/${WizEngine_COMMIT}.zip
)
FetchContent_MakeAvailable(WizEngine)
FetchContent_GetProperties(WizEngine)

# Other dependencies

add_subdirectory(../common build)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include ${SFML_SOURCE_DIR}/include ${WizEngine_SOURCE_DIR}/include ../common/include)

file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h)

add_library(${PARENT_PROJECT_NAME}_libclient STATIC ${SOURCE_FILES})
add_executable(${PARENT_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PARENT_PROJECT_NAME} WizEngine ${PARENT_PROJECT_NAME}_common sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

if (UNIX)
    target_link_libraries(${PARENT_PROJECT_NAME} pthread)
endif (UNIX)

#
# Deletes the old res folder and copies the latest one
# NOTE: Cmake doesn't refresh the res folder unless there are compilation changes
# ideally it would when there are file changes in res but I don't know how to
# achieve that
#
add_custom_command(TARGET ${PARENT_PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove_directory
	$<TARGET_FILE_DIR:${PARENT_PROJECT_NAME}>/res)

add_custom_command(TARGET ${PARENT_PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
	${PROJECT_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PARENT_PROJECT_NAME}>/res)


# Copy openal32.dll for windows

if(WIN32)
    if(CMAKE_SIZEOF_VOID_P EQUAL 8) # 64 bit check
	    add_custom_command(TARGET ${PARENT_PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/cmake-build-debug/_deps/sfml-src/extlibs/bin/x64 $<TARGET_FILE_DIR:${PARENT_PROJECT_NAME}>)
    else()
	    add_custom_command(TARGET ${PARENT_PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${PROJECT_SOURCE_DIR}/cmake-build-debug/_deps/sfml-src/extlibs/bin/x86 $<TARGET_FILE_DIR:${PARENT_PROJECT_NAME}>)
    endif()
endif()
