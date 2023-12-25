set(TARGET Solutions)

set(RELEASE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/ListNode.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0002.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0003.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0005.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0006.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0007.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0008.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution0149.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution1535.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution2956.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution2957.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Solution2961.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SolutionDefault.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SolutionFactory.cpp
)

set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})
set(RELEASE_LIBS Logger)

add_library(${TARGET} STATIC)
target_sources(${TARGET} PRIVATE ${RELEASE_SOURCES})
target_link_libraries(${TARGET} PUBLIC ${RELEASE_LIBS})
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_include_directories(${TARGET} PUBLIC "${INCLUDE_DIRS}")