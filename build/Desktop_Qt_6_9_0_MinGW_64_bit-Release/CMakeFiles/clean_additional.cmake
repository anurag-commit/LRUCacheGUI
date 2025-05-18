# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\LRUCacheGUI_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LRUCacheGUI_autogen.dir\\ParseCache.txt"
  "LRUCacheGUI_autogen"
  )
endif()
