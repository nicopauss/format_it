
set(sources
main.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(${CMAKE_CURRENT_BINARY_DIR}/format_it)

add_definitions(-std=c++11)

add_executable(example ${sources})

target_link_libraries(example format_it)
