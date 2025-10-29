#=== Main App ===
add_executable( ${APP_NAME} main.cpp sudoku_gm.cpp board.cpp module_cli.cpp)
target_compile_features( ${APP_NAME}  PUBLIC cxx_std_17 )
# target_compile_options( ${LIB_NAME} PRIVATE -Wall -pedantic -O3)
target_compile_options( ${APP_NAME} PRIVATE -Wall -pedantic -g)
target_include_directories( ${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib )

# Define where the binary will be output to.
set_target_properties(${APP_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)
