# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Module04_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Module04_autogen.dir/ParseCache.txt"
  "Module04_autogen"
  )
endif()
