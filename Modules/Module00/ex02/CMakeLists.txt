cmake_minimum_required(VERSION 3.16)

project(Exercise02 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define main executable
add_executable(main
  main.cpp
)

# Install executables
install(TARGETS main
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
