set(PURE_LOG_SOURCE_DIR "${PURE_LOG}/source")
set(PURE_LOG_HEADER_DIR "${PURE_LOG}/header")
set(SOURCE_FILES 
    "${PURE_LOG_SOURCE_DIR}/log.cpp"
    "${PURE_LOG_SOURCE_DIR}/consoleOut.cpp"
    "${PURE_LOG_SOURCE_DIR}/fileOut.cpp"
    "${PURE_LOG_SOURCE_DIR}/outputStream.cpp"
    "${PURE_LOG_SOURCE_DIR}/colors.cpp"
)
set(INCLUDE_DIR
    ${INCLUDE}
    ${PURE_LOG_HEADER_DIR}
    ${PURE_LOG_SOURCE_DIR}
)
set(PRECOMPILED_HEADERS
    "${PURE_LOG_HEADER_DIR}/stdIncludes.hpp"
)

add_library(PureLog STATIC)
target_sources(PureLog PRIVATE ${SOURCE_FILES})
target_include_directories(PureLog PUBLIC ${INCLUDE_DIR})
target_precompile_headers(PureLog PRIVATE ${PRECOMPILED_HEADERS})

set_target_properties(PureLog PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${ROOT_DIR}/lib"
    OUTPUT_NAME "PureLog"
    PREFIX ""
    SUFFIX ".lib"
)