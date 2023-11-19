set(TARGET Logger)

if(CMAKE_MAX_LOG_LEVEL LESS 0 OR CMAKE_MAX_LOG_LEVEL GREATER 6)
    message(
        FATAL_ERROR
            "CMAKE_MAX_LOG_LEVEL should be in the range [0, 6]. CMAKE_MAX_LOG_LEVEL=${CMAKE_MAX_LOG_LEVEL}"
    )
endif()

set(RELEASE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/private/LogEnums.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/private/LogHandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/private/LogPrefix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/private/LogStream.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/private/STDDumpers.cpp
)

# set includes
set(INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${TARGET} STATIC)
target_sources(${TARGET} PRIVATE ${RELEASE_SOURCES})
target_compile_features(${TARGET} PRIVATE cxx_std_17)
target_compile_definitions(${TARGET} PRIVATE "-DCMAKE_MAX_LOG_LEVEL=${CMAKE_MAX_LOG_LEVEL}")
target_include_directories(${TARGET} PUBLIC "${INCLUDE_DIRS}")