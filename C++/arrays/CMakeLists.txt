#author Stoyan Lupov
cmake_minimum_required(VERSION 3.5.1)

#ARRAYS_LIB project is defined in parent (root) directory
set(ARRAYS_ROOT_DIR "${PROJECT_ROOT_DIR}/arrays")

file(GLOB _SOURCES
        "${ARRAYS_ROOT_DIR}/*.cpp"
        "${ARRAYS_ROOT_DIR}/search/*.cpp"
        "${ARRAYS_ROOT_DIR}/sorting/*.cpp"
        "${ARRAYS_ROOT_DIR}/sorting/*.cpp"
        "${ARRAYS_ROOT_DIR}/nbulecture/1D/*.cpp"
        "${ARRAYS_ROOT_DIR}/nbulecture/2D/*.cpp"
        "${ARRAYS_ROOT_DIR}/nbulecture/homework/*.cpp"
        "${ARRAYS_ROOT_DIR}/nbulecture/homework/skeleton/*.cpp"
        "${ARRAYS_ROOT_DIR}/nbulecture/*.cpp")


#Generate the static library from the sources
add_library(${ARRAYS_LIB} STATIC
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${ARRAYS_LIB} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${ARRAYS_LIB} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
            ${IWYU_BINARY_PATH})
endif(USE_IWYU)


target_link_libraries(
        ${ARRAYS_LIB}
        ${DATA_GENERATOR_LIB}
        ${CMAKE_DL_LIBS})      # -ldl flag

#make array library depend on datagenerator library, because library's
#compilation depends on successful creation of datagenerator library ->
#therefore datagenerator library should be created first
add_dependencies(${ARRAYS_LIB} ${DATA_GENERATOR_LIB})