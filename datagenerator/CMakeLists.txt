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

add_executable(${DATA_GENERATOR}
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${DATA_GENERATOR} PROPERTY CXX_STANDARD 14)

target_link_libraries(${DATA_GENERATOR} -static-libgcc -static-libstdc++)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${DATA_GENERATOR} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
            ${IWYU_BINARY_PATH})
endif(USE_IWYU)

#generate symbolic link for resourcebuilder after build is ready
#also add the -f (--force) command in order to
#override the existing symbolic link (if any)
#add_custom_command(
#        TARGET ${DATA_GENERATOR} POST_BUILD
#        COMMAND
#        mklink datagenerator datageneratorSymLink)
#
#
##move symbolic link to project build directory
#add_custom_command(
#        TARGET ${DATA_GENERATOR} POST_BUILD
#        COMMAND
#        move datageneratorSymLink ${PROJECT_ROOT_DIR}/build/datagenerator)

#generate symbolic link for resourcebuilder after build is ready
#also add the -f (--force) command in order to
#override the existing symbolic link (if any)
#add_custom_command(
#        TARGET ${DATA_GENERATOR} POST_BUILD
#        COMMAND
#        ln -sf datagenerator datageneratorSymLink)
#
#
##move symbolic link to project build directory
#add_custom_command(
#        TARGET ${DATA_GENERATOR} POST_BUILD
#        COMMAND
#        mv datageneratorSymLink ${PROJECT_ROOT_DIR}/build/datagenerator)


#add_dependencies(${DATA_GENERATOR})
