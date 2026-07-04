function(move_global_module_fragment_to_top input output)
    file(READ "${input}" source)

    # Module builds need the global module fragment to be the first token.
    # Move any existing plain `module;` control line to the top of the generated file.
    string(REGEX REPLACE "(^|\n)[ \t]*module[ \t]*;[^\n]*(\n|$)" "\\1" source "${source}")

    get_filename_component(output_dir "${output}" DIRECTORY)
    file(MAKE_DIRECTORY "${output_dir}")
    file(WRITE "${output}" "module;\n\n${source}")

    set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS "${input}")
endfunction()

set(PURE_LOG_SOURCE_DIR "${PURE_LOG}")
set(PURE_LOG_HEADER_DIR "${PURE_LOG}")

set(PURE_LOG_IMPLEMENTATION_FILES
    "${PURE_LOG}/log.cpp"
    "${PURE_LOG}/colors.cpp"
    "${PURE_LOG}/outputStream.cpp"
    "${PURE_LOG}/consoleOut.cpp"
    "${PURE_LOG}/fileOut.cpp"
)

set(PURE_LOG_MODULE_FILES
    "${PURE_LOG}/pureLog.mpp"
    "${PURE_LOG}/log.mpp"
    "${PURE_LOG}/colors.mpp"
    "${PURE_LOG}/formatting.mpp"
    "${PURE_LOG}/outputStream.mpp"
    "${PURE_LOG}/consoleOut.mpp"
    "${PURE_LOG}/fileOut.mpp"
    "${PURE_LOG}/logger.mpp"
)

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_MODULE_SOURCE_FILES)

    foreach(SOURCE_FILE IN LISTS PURE_LOG_IMPLEMENTATION_FILES)
        get_filename_component(SOURCE_NAME "${SOURCE_FILE}" NAME)
        set(MODULE_SOURCE_FILE "${CMAKE_CURRENT_BINARY_DIR}/module-mode/${SOURCE_NAME}")

        move_global_module_fragment_to_top("${SOURCE_FILE}" "${MODULE_SOURCE_FILE}")
        list(APPEND PURE_LOG_MODULE_SOURCE_FILES "${MODULE_SOURCE_FILE}")
    endforeach()

    add_library(PureLog STATIC ${PURE_LOG_MODULE_SOURCE_FILES})
    target_compile_definitions(PureLog PRIVATE PURE_LOG_USE_MODULES=1)
    if(PURE_LOG_IMPORT_STD)
        target_compile_definitions(PureLog PRIVATE PURE_LOG_IMPORT_STD=1)
        set_target_properties(PureLog PROPERTIES CXX_MODULE_STD ON)
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            target_link_options(PureLog INTERFACE -Wl,--allow-multiple-definition)
        endif()
    endif()
    target_include_directories(PureLog PRIVATE "${PURE_LOG_HEADER_DIR}")

    set_source_files_properties(${PURE_LOG_MODULE_FILES} PROPERTIES LANGUAGE CXX)
    target_sources(PureLog
        PUBLIC
            FILE_SET cxx_modules
            TYPE CXX_MODULES
            BASE_DIRS "${PURE_LOG_SOURCE_DIR}"
            FILES ${PURE_LOG_MODULE_FILES}
    )

    set_target_properties(PureLog PROPERTIES CXX_SCAN_FOR_MODULES ON)
else()
    add_library(PureLog STATIC ${PURE_LOG_IMPLEMENTATION_FILES})
    set_target_properties(PureLog PROPERTIES CXX_SCAN_FOR_MODULES OFF)
endif()

target_include_directories(PureLog PUBLIC
    "${INCLUDE}"
    "${PURE_LOG_HEADER_DIR}"
)
target_compile_features(PureLog PUBLIC cxx_std_23)

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_OUTPUT_NAME "modules-pureLog")
else()
    set(PURE_LOG_OUTPUT_NAME "pureLog")
endif()

set_target_properties(PureLog PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${ROOT_DIR}/lib/$<LOWER_CASE:$<CONFIG>>"
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    OUTPUT_NAME "${PURE_LOG_OUTPUT_NAME}"
    PREFIX ""
    SUFFIX ".lib"
)
