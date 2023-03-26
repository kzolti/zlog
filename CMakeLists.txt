cmake_minimum_required(VERSION 3.5)

project(zlog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(zlog STATIC
    src/log.h
    src/logimpl.h src/logimpl.cpp
)
set_property(TARGET zlog PROPERTY CXX_STANDARD 11)
install(TARGETS zlog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#install(FILES log.h DESTINATION include)
#install(FILES logimpl.h DESTINATION include)
