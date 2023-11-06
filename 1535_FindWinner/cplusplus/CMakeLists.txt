cmake_minimum_required(VERSION 3.16)

message(STATUS "CMake version: ${CMAKE_VERSION}")

project(
    Solution_1535
    VERSION 1.0.0
    LANGUAGES CXX
)

set(SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/helper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution.cpp)

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

message("TARGET          : ${TARGET}")
message("INCLUDE_DIRS    : ${INCLUDE_DIRS}")
message("SRC_FILES       : ${SRC_FILES}")

add_executable(${PROJECT_NAME} ${SRC_FILES})