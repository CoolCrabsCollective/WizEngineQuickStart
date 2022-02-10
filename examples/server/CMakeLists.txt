cmake_minimum_required(VERSION 3.7)
project(WizEngineServer VERSION 0.1)

# static linking of libraries on linux
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,-lpthread -lc")
add_compile_definitions(OS_UNIX) # applies C++ macro

# Note: os_finder.h ensures OS_SWITCH is defined when no other OS is defined


#
# Set C++ version
#
set(CMAKE_CXX_STANDARD 20)


if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux64/)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/out/linux32/)
endif()

# Fetches SFML dependency and loads its CMakeLists.txt
include(FetchContent)
FetchContent_Declare(
        sfml
        URL https://github.com/SFML/SFML/archive/ef8d6ee7f710fff9bdaf69c6bb3660fa4d3a8958.zip
)
FetchContent_MakeAvailable(sfml)

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
FetchContent_GetProperties(SFML)

# Other dependencies

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include ${SFML_SOURCE_DIR}/include)

file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network pthread)

#
# Deletes the old res folder and copies the latest one
# NOTE: Cmake doesn't refresh the res folder unless there are compilation changes
# ideally it would when there are file changes in res but I don't know how to
# achieve that
#
# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} PRE_BUILD
#         COMMAND ${CMAKE_COMMAND} -E remove_directory
#         $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res)

# add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_directory
#         ${PROJECT_SOURCE_DIR}/res $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>/res)
