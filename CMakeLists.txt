cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(design-patterns LANGUAGES CXX)

file(GLOB_RECURSE _sources RELATIVE
  "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

foreach(_source IN LISTS _sources)
  get_filename_component(_dest ${_source} NAME_WE)
  add_executable(${_dest} ${_source})
  set_target_properties(${_dest}
    PROPERTIES
      CXX_STANDARD 17
      CXX_EXTENSIONS OFF
      CXX_STANDARD_REQUIRED ON
      POSITION_INDEPENDENT_CODE 1
  )
endforeach()
