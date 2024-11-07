cmake_minimum_required(VERSION 3.16)

project(Exercise03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define exercise03 executable
add_executable(exercise03
  main.cpp
  Contact.cpp
  Phonebook.cpp
)

# Install executables
install(TARGETS exercise03
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
