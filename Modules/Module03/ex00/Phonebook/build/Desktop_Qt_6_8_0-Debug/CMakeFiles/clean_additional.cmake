# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Phonebook_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Phonebook_autogen.dir/ParseCache.txt"
  "Phonebook_autogen"
  )
endif()
