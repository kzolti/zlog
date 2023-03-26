cmake_minimum_required(VERSION 3.5)

project(zlog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_library(zlog STATIC
    src/logimpl.cpp
    src/log.h
    src/logimpl.h
)

set_property(TARGET zlog PROPERTY CXX_STANDARD 11)

install(TARGETS zlog
    ARCHIVE DESTINATION lib
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/log.h ${CMAKE_CURRENT_SOURCE_DIR}/src/logimpl.h
    DESTINATION include
)
add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake
)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY
)
