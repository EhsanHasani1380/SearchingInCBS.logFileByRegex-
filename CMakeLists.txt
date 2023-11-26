cmake_minimum_required(VERSION 3.0.0)
project(information VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(information main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)
include(CPack)
