cmake_minimum_required(VERSION 3.5)

project(example LANGUAGES CXX)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set zlog include and library
#set(zlog_include_dir ${CMAKE_CURRENT_BINARY_DIR}/../src)
set(zlog_include_dir ${CMAKE_SOURCE_DIR}/../src)
include_directories(${zlog_include_dir})
add_library(zlog STATIC ${zlog_include_dir}/log.h ${zlog_include_dir}/logimpl.h ${zlog_include_dir}/logimpl.cpp ${zlog_include_dir}/logstream.h ${zlog_include_dir}/logstream.cpp)


add_executable(myapp main.cpp)

# Link the zlog library to your project
target_link_libraries(myapp zlog)

install(TARGETS myapp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
