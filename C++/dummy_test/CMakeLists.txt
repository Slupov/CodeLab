#Author Stoyan Lupov

#Since this is a syb-directory CMakeLists.txt file some global variables
#are used from the project root CMakeLists.txt file.
#In order to not override them we will name similar variables with beggining
#underscore '_'

cmake_minimum_required(VERSION 3.5.1)

#RESOURCE_BUILDER project is defined in parent (root) directory

#Additional include directories - Empty for now
#include_directories(})

#file(GLOB...) allows for wildcard additions:
file(GLOB _SOURCES "*.cpp")

#generate datagenerator binary
add_executable(${TEST}
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${TEST} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
#if(USE_IWYU)
#    set_property(TARGET ${TEST} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
#            ${IWYU_BINARY_PATH})
#endif(USE_IWYU)

if (WIN32)
    #generate symbolic link for resourcebuilder after build is ready
    #also add the -f (--force) command in order to
    #override the existing symbolic link (if any)
    add_custom_command(
            TARGET ${TEST} POST_BUILD
            COMMAND
            mklink dummy_test/dummy_test testSymLink)


    ##move symbolic link to project build directory
    add_custom_command(
            TARGET ${TEST} POST_BUILD
            COMMAND
            move testSymLink ${PROJECT_ROOT_DIR}/build/test)
endif (WIN32)

if (UNIX)
    #generate symbolic link for resourcebuilder after build is ready
    #also add the -f (--force) command in order to
    #override the existing symbolic link (if any)
    add_custom_command(
            TARGET ${TEST} POST_BUILD
            COMMAND
            ln -sf dummy_test/dummy_test testSymLink)


    ##move symbolic link to project build directory
    add_custom_command(
            TARGET ${TEST} POST_BUILD
            COMMAND
            mv testSymLink ${PROJECT_ROOT_DIR}/build/test)

endif (UNIX)