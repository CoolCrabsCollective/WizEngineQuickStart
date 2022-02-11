cmake_minimum_required(VERSION 3.7)

get_filename_component(PARENT_PROJECT_PATH .. ABSOLUTE)
get_filename_component(PARENT_PROJECT_NAME ${PARENT_PROJECT_PATH} NAME)

project(${PARENT_PROJECT_NAME}_server)

# static linking of libraries on linux
set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstdc++ ${CMAKE_CXX_STANDARD_LIBRARIES}")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Bstatic,-lpthread -lc")
add_compile_definitions(OS_UNIX) # applies C++ macro

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
        SFML
        URL https://github.com/SFML/SFML/archive/ef8d6ee7f710fff9bdaf69c6bb3660fa4d3a8958.zip
)
FetchContent_MakeAvailable(SFML)

# this creates the variables SFML_SOURCE_DIR, SFML_BINARY_DIR and SFML_POPULATED
# then SFML_SOURCE_DIR is used below to include the header files
FetchContent_GetProperties(SFML)


FetchContent_Declare(
	WizEngine
	URL https://github.com/WheezyWiseWizards/WizEngine/archive/d8a9aa940077c503f9212752ed48cba0264ac0ad.zip
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

add_library(${PARENT_PROJECT_NAME}_libserver STATIC ${SOURCE_FILES})
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} WizEngine ${PARENT_PROJECT_NAME}_common sfml-system sfml-window sfml-graphics sfml-audio sfml-network pthread)
