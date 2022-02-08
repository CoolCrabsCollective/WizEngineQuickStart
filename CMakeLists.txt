cmake_minimum_required(VERSION 3.7)
project(GameTemplate)


find_package(OpenGL)
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

set(CMAKE_CXX_STANDARD 17)

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