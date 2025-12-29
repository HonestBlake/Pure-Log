# Package cmake list file

set(BETTER_LOGGER "${ROOT_DIR}/better logger")
set(SOURCE 
    "${BETTER_LOGGER}/source/defaultLoggers.cpp"
    "${BETTER_LOGGER}/source/defaultLogStacks.cpp"
    "${BETTER_LOGGER}/source/loggers.cpp"
    "${BETTER_LOGGER}/source/logStacks.cpp"
)
set(HEADER_DIRECTORIES
    "${BETTER_LOGGER}/header"
    "${BETTER_LOGGER}/source"
    "${BETTER_LOGGER}"
    "${ROOT_DIR}/include"
)

add_library(BetterLogger STATIC ${SOURCE})
target_include_directories(BetterLogger PUBLIC ${HEADER_DIRECTORIES})
set_target_properties(BetterLogger PROPERTIES
    OUTPUT_NAME "betterLogger"
    PREFIX ""
    SUFFIX ".lib"
)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR) # Only set this if the project is built locally
    set_target_properties(BetterLogger PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${ROOT_DIR}/binary"
    )
endif()