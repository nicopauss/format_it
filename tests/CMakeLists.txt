
set(sources
main.cpp
test_format_float.cpp
test_format_helpers.cpp
test_format_integers.cpp
test_format_it.cpp
test_format_stl.cpp
test_stack_format.cpp
gtest/gtest-all.cc
)

# For gtest
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/format_it)

if(CYGWIN)
  add_definitions(-std=gnu++11)
else(CYGWIN)
  add_definitions(-std=c++11)
endif(CYGWIN)

add_executable(tests ${sources})

target_link_libraries(tests format_it)
