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
add_executable(${DATA_GENERATOR}
               ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${DATA_GENERATOR} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${DATA_GENERATOR} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
            ${IWYU_BINARY_PATH})
endif(USE_IWYU)

target_link_libraries(${DATA_GENERATOR} ${DATA_GENERATOR_LIB})

if (WIN32)
    #generate symbolic link for resourcebuilder after build is ready
    #also add the -f (--force) command in order to
    #override the existing symbolic link (if any)
    add_custom_command(
            TARGET ${DATA_GENERATOR} POST_BUILD
            COMMAND
            mklink tools/datagenerator/datagenerator datageneratorSymLink)


    ##move symbolic link to project build directory
    add_custom_command(
            TARGET ${DATA_GENERATOR} POST_BUILD
            COMMAND
            move datageneratorSymLink ${PROJECT_ROOT_DIR}/build/datagenerator)
endif (WIN32)

if (UNIX)
    #generate symbolic link for resourcebuilder after build is ready
    #also add the -f (--force) command in order to
    #override the existing symbolic link (if any)
    add_custom_command(
            TARGET ${DATA_GENERATOR} POST_BUILD
            COMMAND
            ln -sf tools/datagenerator/datagenerator datageneratorSymLink)


    ##move symbolic link to project build directory
    add_custom_command(
            TARGET ${DATA_GENERATOR} POST_BUILD
            COMMAND
            mv datageneratorSymLink ${PROJECT_ROOT_DIR}/build/datagenerator)

endif (UNIX)

#make datagenerator binary depend on datagenerator library, because binary's
#compilation depends on successful creation of datagenerator library ->
#therefore datagenerator library should be created first
add_dependencies(${DATA_GENERATOR} ${DATA_GENERATOR_LIB})