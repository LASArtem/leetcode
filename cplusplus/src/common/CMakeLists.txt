set(TARGET Common)

set(RELEASE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/dumper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/helper.cpp
)

# set includes
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${TARGET} STATIC)
target_sources(${TARGET} PRIVATE ${RELEASE_SOURCES})
target_include_directories(${TARGET} PUBLIC "${INCLUDE_DIRS}")