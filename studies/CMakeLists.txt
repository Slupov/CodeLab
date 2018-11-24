#Author Stoyan Lupov

#Since this is a syb-directory CMakeLists.txt file some global variables
#are used from the project root CMakeLists.txt file.
#In order to not override them we will name similar variables with beggining
#underscore '_'

cmake_minimum_required(VERSION 3.5.1)

#ARRAYS_LIB project is defined in parent (root) directory
set(STUDIES_ROOT_DIR "${PROJECT_ROOT_DIR}/studies")

#file(GLOB...) allows for wildcard additions:
file(GLOB _SOURCES
        "${STUDIES_ROOT_DIR}/*.cpp"
        "${STUDIES_ROOT_DIR}/algorithms/*.cpp")

add_library(${STUDIES_LIB} STATIC
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${STUDIES_LIB} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${STUDIES_LIB} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
            ${IWYU_BINARY_PATH})
endif(USE_IWYU)

target_link_libraries(${STUDIES_LIB} -static-libgcc -static-libstdc++)