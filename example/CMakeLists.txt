add_executable(Example
    "${EXAMPLE}/example.cpp"
)

target_link_libraries(Example PRIVATE PureLog)

if(PURE_LOG_USE_MODULES)
    target_compile_definitions(Example PRIVATE PURE_LOG_USE_MODULES=1)
    if(PURE_LOG_IMPORT_STD)
        target_compile_definitions(Example PRIVATE PURE_LOG_IMPORT_STD=1)
        set_target_properties(Example PROPERTIES CXX_MODULE_STD ON)
    endif()
    set_target_properties(Example PROPERTIES CXX_SCAN_FOR_MODULES ON)
else()
    set_target_properties(Example PROPERTIES CXX_SCAN_FOR_MODULES OFF)
endif()

if(PURE_LOG_USE_MODULES)
    set(PURE_LOG_EXAMPLE_OUTPUT_NAME "modules-example")
else()
    set(PURE_LOG_EXAMPLE_OUTPUT_NAME "example")
endif()

set_target_properties(Example PROPERTIES
    CXX_EXTENSIONS OFF
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
    RUNTIME_OUTPUT_DIRECTORY "${EXAMPLE}/bin/$<LOWER_CASE:$<CONFIG>>"
    OUTPUT_NAME "${PURE_LOG_EXAMPLE_OUTPUT_NAME}"
)
