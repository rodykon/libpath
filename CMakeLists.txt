cmake_minimum_required(VERSION 3.0.0)
project(libpath VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB SOURCES
    "src/*.cpp"
    "src/constraints/*.cpp"
    "src/curve/*.cpp"
    "src/curve_splitter/*.cpp"
    "src/math/*.cpp"
    "src/profile/*.cpp"
    "src/util/*.cpp"
    "test/*.cpp"
)

include_directories(include test)

add_executable(libpath ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()
