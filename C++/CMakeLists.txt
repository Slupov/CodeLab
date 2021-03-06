#author Stoyan Lupov
cmake_minimum_required(VERSION 3.5.1)

#define root project
set(ROOT_PROJECT codelab)
project(${ROOT_PROJECT})

#default build type
#set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

set(PROJECT_ROOT_DIR "${${ROOT_PROJECT}_SOURCE_DIR}")

set(CPP_VERSION_FLAG "-std=c++14")
set(WARNING_FLAGS "-Wall -Wextra -Wfloat-equal -Wundef -Wuninitialized")
set(WARNING_FLAGS "${WARNING_FLAGS} -Wreorder -Wshadow -Wpointer-arith")
set(WARNING_FLAGS "${WARNING_FLAGS} -Wcast-align -Wcast-qual -Wconversion")
set(WARNING_FLAGS "${WARNING_FLAGS} -Wunused-parameter")

#set global compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_VERSION_FLAG} ${WARNING_FLAGS}")

#manually add Position Independant Code
#to compiler flags -> it could decrease the runtime performance
#but it will require no source recompilation when new file is added
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

#include general include directories. This will affect all target includes
#that are invoked with add_directory command.
include_directories(${PROJECT_ROOT_DIR})

file(GLOB _SOURCES
        "${PROJECT_ROOT_DIR}/*.cpp"
        "${PROJECT_ROOT_DIR}/tools/datagenerator/*.cpp"
        "${PROJECT_ROOT_DIR}/studies/*.cpp"
        "${PROJECT_ROOT_DIR}/studies/algorithms/*.cpp"
        "${PROJECT_ROOT_DIR}/arrays/*.cpp"
        "${PROJECT_ROOT_DIR}/engine/*.cpp"
        "${PROJECT_ROOT_DIR}/dummy_test/*.cpp"
        )

#### START CHILD PROJECT DEFINES ####
#define arrays project
set(ARRAYS_LIB arrays)
project(${ARRAYS_LIB})

#define studies project
set(STUDIES_LIB studies)
project(${STUDIES_LIB})

#define data generator library project
set(DATA_GENERATOR_LIB datageneratorlib)
project(${DATA_GENERATOR_LIB})

#define data generator project
set(DATA_GENERATOR datagenerator)
project(${DATA_GENERATOR})

#define dummy test project
set(TEST dummy_test)
project(${TEST})

#define asap cpp advanced project
set(ASAP_CPP_ADVANCED asapcppadvanced)
project(${ASAP_CPP_ADVANCED})

#reuse project flags and start other cmake files
add_subdirectory(${PROJECT_ROOT_DIR}/studies)
add_subdirectory(${PROJECT_ROOT_DIR}/tools/datageneratorlib)
add_subdirectory(${PROJECT_ROOT_DIR}/tools/datagenerator)
add_subdirectory(${PROJECT_ROOT_DIR}/arrays)
add_subdirectory(${PROJECT_ROOT_DIR}/engine)
add_subdirectory(${PROJECT_ROOT_DIR}/dummy_test)
add_subdirectory(${PROJECT_ROOT_DIR}/asapcppadvanced)