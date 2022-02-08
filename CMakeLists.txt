cmake_minimum_required(VERSION 3.7)
project(GameTemplate)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -ansi -Wno-deprecated -pthread)
endif()

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        sfml
        URL https://github.com/TomBebb/SFML-switch/archive/46dfeda83459649a145c6eb6a0a79b19d0a35305.zip
)
FetchContent_MakeAvailable(sfml)

find_package(OpenGL)
#find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
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