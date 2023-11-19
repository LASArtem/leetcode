cmake_minimum_required(VERSION 3.16)

message(STATUS "CMake version: ${CMAKE_VERSION}")

project(
    LeetCode_Solutions
    VERSION 1.0.0
    LANGUAGES CXX
)


add_subdirectory(src)

set(SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})

set(RELEASE_LIBS Solutions Logger)
target_link_libraries(${PROJECT_NAME} ${RELEASE_LIBS})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

message("TARGET          : ${TARGET}")
message("SRC_FILES       : ${SRC_FILES}")
message("RELEASE_LIBS    : ${RELEASE_LIBS}")

