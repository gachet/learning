set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(${PROJECT_SOURCE_DIR}/src/ch16 CH16_SOURCE_FILES)
add_executable(ch16 ${CH16_SOURCE_FILES})
