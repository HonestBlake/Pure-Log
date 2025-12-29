
add_executable(Example
    "${EXAMPLE}/example.cpp"
)

target_link_libraries(Example PRIVATE PureLog)

set_target_properties(Example PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${EXAMPLE}
)