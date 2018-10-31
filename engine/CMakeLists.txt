#author Stoyan Lupov

cmake_minimum_required(VERSION 3.5.1)


#define engine project
set(ENGINE_PROJECT engine)
project(${ENGINE_PROJECT})

set(ENGINE_ROOT_DIR "${PROJECT_ROOT_DIR}/engine")

set(ENGINE_BUILD_DIR "${PROJECT_ROOT_DIR}/build/engine")

#define names for engine's static libraries

#### START CHILD PROJECT DEFINES ####
#### END CHILD PROJECT DEFINES ####


#file(GLOB...) allows for wildcard additions:
file(GLOB _SOURCES
        "${ENGINE_ROOT_DIR}/*.cpp")

#generate engine binary
add_executable(${ENGINE_PROJECT}
        ${_SOURCES})


#adding -std=c++14 flag
set_property(TARGET ${ENGINE_PROJECT} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${ENGINE_PROJECT} PROPERTY
            CXX_INCLUDE_WHAT_YOU_USE ${IWYU_BINARY_PATH})
endif(USE_IWYU)


target_link_libraries(
        ${ENGINE_PROJECT}
        ${ARRAYS_LIB}
        ${CMAKE_DL_LIBS})