#author Stoyan Lupov
cmake_minimum_required(VERSION 3.5.1)

#ARRAYS_LIB project is defined in parent (root) directory
set(ASAP_CPP_ADVANCED_ROOT_DIR "${PROJECT_ROOT_DIR}/asapcppadvanced")

file(GLOB _SOURCES
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/00_functions/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/01_overloading/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/02_pointers/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/03_dynamicmemory/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/04_oop/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/05_classinterface/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/06_files/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/07_graphicssdl2/*.cpp"
        "${ASAP_CPP_ADVANCED_ROOT_DIR}/08_exceptions/*.cpp"
)

#Generate the static library from the sources
add_library(${ASAP_CPP_ADVANCED} STATIC
        ${_SOURCES})

#adding -std=c++14 flag
set_property(TARGET ${ASAP_CPP_ADVANCED} PROPERTY CXX_STANDARD 14)

#invoke include-what-you-use (if it's enabled) for the current project
if(USE_IWYU)
    set_property(TARGET ${ASAP_CPP_ADVANCED} PROPERTY CXX_INCLUDE_WHAT_YOU_USE
            ${IWYU_BINARY_PATH})
endif(USE_IWYU)


target_link_libraries(
        ${ASAP_CPP_ADVANCED}
        ${DATA_GENERATOR_LIB}
        ${CMAKE_DL_LIBS})      # -ldl flag

#make array library depend on datagenerator library, because library's
#compilation depends on successful creation of datagenerator library ->
#therefore datagenerator library should be created first
add_dependencies(${ASAP_CPP_ADVANCED} ${DATA_GENERATOR_LIB})