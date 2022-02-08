cmake_minimum_required(VERSION 3.7)
project(GameTemplate)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread -Wpedantic)
endif()

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        sfml
        URL https://github.com/SFML/SFML/archive/ef8d6ee7f710fff9bdaf69c6bb3660fa4d3a8958.zip
)
FetchContent_MakeAvailable(sfml)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

include_directories(include)
file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h)

add_library(GameTemplate_lib ${SOURCE_FILES})
add_executable(GameTemplate ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

if (UNIX)
    target_link_libraries(${PROJECT_NAME} pthread)
endif (UNIX)