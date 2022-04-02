cmake_minimum_required(VERSION 3.7)

get_filename_component(PARENT_PROJECT_PATH .. ABSOLUTE)
get_filename_component(PARENT_PROJECT_NAME ${PARENT_PROJECT_PATH} NAME)

project(${PARENT_PROJECT_NAME}_server)

set(WizEngine_COMMIT master)
set(SFML_COMMIT 8f6903d00853fd3db395a557733ae65a14f37c01)

# static linking of libraries on linux
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,-lpthread -lc")
add_compile_definitions(OS_UNIX) # applies C++ macro

#
# Set C++ version
#
set(CMAKE_CXX_STANDARD 20)

if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/linux64/)
else()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/linux32/)
endif()

# Fetches SFML dependency and loads its CMakeLists.txt
include(FetchContent)
FetchContent_Declare(SFML
        URL https://github.com/SFML/SFML/archive/${SFML_COMMIT}.zip)
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

add_subdirectory(../common build)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL)
find_package(Threads REQUIRED)

# include and source files
include_directories(include
        ${SFML_SOURCE_DIR}/include
        ${WizEngine_SOURCE_DIR}/include
        ${Box2D_SOURCE_DIR}/Box2D/Box2D
        ../common/include)

file(GLOB SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/src/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*.h
        ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp
        ${PROJECT_SOURCE_DIR}/include/*/*/*.h)

add_library(${PARENT_PROJECT_NAME}_libserver STATIC ${SOURCE_FILES})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} WizEngine ${PARENT_PROJECT_NAME}_common sfml-system sfml-window sfml-graphics sfml-audio sfml-network pthread)
