cmake_minimum_required(VERSION 2.5)
project(CssOptimizer)

set(EXECUTABLE_NAME "CssOptimizer")

set(SOURCE_FILES
    functions.c
    functions.h
    list.c
    list.h
    main.c
)

file(COPY style.css DESTINATION ${CMAKE_BINARY_DIR})
file(COPY style2.css DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})