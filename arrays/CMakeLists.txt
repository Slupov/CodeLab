#author Stoyan Lupov
cmake_minimum_required(VERSION 3.5.1)

#ARRAYS_LIB project is defined in parent (root) directory
set(ARRAYS_ROOT_DIR "${PROJECT_ROOT_DIR}/arrays")

file(GLOB _SOURCES
        "${ARRAYS_ROOT_DIR}/*.cpp")

#Generate the static library from the sources
add_library(${ARRAYS_LIB} STATIC
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${ARRAYS_LIB} PROPERTY CXX_STANDARD 14)

target_link_libraries(${ARRAYS_LIB})
