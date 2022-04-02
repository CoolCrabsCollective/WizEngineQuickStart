cmake_minimum_required(VERSION 3.7)

get_filename_component(PARENT_PROJECT_PATH .. ABSOLUTE)
get_filename_component(PARENT_PROJECT_NAME ${PARENT_PROJECT_PATH} NAME)

project(${PARENT_PROJECT_NAME}_common)

set(WizEngine_COMMIT master)
set(SFML_COMMIT 8f6903d00853fd3db395a557733ae65a14f37c01)
set(SFML_SWITCH_COMMIT master)
set(BOX2D_CMAKE_COMMIT master)

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
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,-lpthread -lc")
    add_compile_definitions(OS_UNIX) # applies C++ macro
elseif(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    add_compile_definitions(OS_SWITCH) # applies C++ macro
    set(CMAKE_USER_MAKE_RULES_OVERRIDE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/CompilerOptionsOverride.cmake")
endif()


#
# Set C++ version
#
set(CMAKE_CXX_STANDARD 20)


# Fetches SFML dependency and loads its CMakeLists.txt
include(FetchContent)
if(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    FetchContent_Declare(SFML
            URL https://github.com/WheezyWiseWizards/SFML-switch/archive/${SFML_SWITCH_COMMIT}.zip)
else()
    FetchContent_Declare(SFML
            URL https://github.com/SFML/SFML/archive/${SFML_COMMIT}.zip)
endif()
FetchContent_MakeAvailable(SFML)

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
FetchContent_GetProperties(SFML)

FetchContent_Declare(WizEngine
        URL https://github.com/WheezyWiseWizards/WizEngine/archive/${WizEngine_COMMIT}.zip)
FetchContent_MakeAvailable(WizEngine)
FetchContent_GetProperties(WizEngine)


# Fetches Box2D dependency and loads its CMakeLists.txt
FetchContent_Declare(Box2D
        GIT_REPOSITORY https://github.com/WheezyWiseWizards/Box2D-cmake.git
        GIT_TAG ${BOX2D_CMAKE_COMMIT})
FetchContent_MakeAvailable(Box2D)
FetchContent_GetProperties(Box2D SOURCE_DIR Box2D_SOURCE_DIR)

# Other dependencies

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include
        ${SFML_SOURCE_DIR}/include
        ${WizEngine_SOURCE_DIR}/include
        ${Box2D_SOURCE_DIR}/Box2D/Box2D)

if(CMAKE_TOOLCHAIN_FILE MATCHES ".*DevkitA64Libnx.cmake")
    include_directories(${LIBNX_INCLUDE_DIR})
endif()

file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})
