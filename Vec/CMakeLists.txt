cmake_minimum_required(VERSION 3.5)

project(Vec LANGUAGES C)

add_executable(Vec main.c)

install(TARGETS Vec
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
