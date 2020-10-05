cmake_minimum_required(VERSION 3.0.0)
project(libpath VERSION 0.1.0)

include(CTest)
enable_testing()

set(SOURCE_FILES src/curve/HermiteQuinticCurve.cpp src/util/CSVWriter.cpp test/TestCurve.cpp src/main.cpp)

add_executable(libpath ${SOURCE_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include_directories(include test)

message(STATUS "SOURCE_FILES: ${SOURCE_FILES}")

macro(print_all_variables)
    message(STATUS "print_all_variables------------------------------------------{")
    get_cmake_property(_variableNames VARIABLES)
    foreach (_variableName ${_variableNames})
        message(STATUS "${_variableName}=${${_variableName}}")
    endforeach()
    message(STATUS "print_all_variables------------------------------------------}")
endmacro()
