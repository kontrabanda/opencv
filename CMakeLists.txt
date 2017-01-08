cmake_minimum_required (VERSION 2.6)
project (pobr)

find_package(OpenCV REQUIRED)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(SOURCE_INPUT_PATH ${PROJECT_BINARY_DIR}/src)

file(GLOB ALL_SRC
    ${SOURCE_INPUT_PATH}/*.h
    ${SOURCE_INPUT_PATH}/*.cpp
)

add_executable(pobr ${ALL_SRC})

target_link_libraries(pobr ${OpenCV_LIBS})
