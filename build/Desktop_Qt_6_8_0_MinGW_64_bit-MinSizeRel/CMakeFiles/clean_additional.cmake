# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "MinSizeRel")
  file(REMOVE_RECURSE
  "CMakeFiles\\Inspector_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Inspector_autogen.dir\\ParseCache.txt"
  "Inspector_autogen"
  )
endif()
