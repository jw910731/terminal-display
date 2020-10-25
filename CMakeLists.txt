cmake_minimum_required(VERSION 3.0)
project(TerminalDisplay)
set(CMAKE_CXX_STANDARD 17)

## Target
add_subdirectory(src)
add_executable(TerminalDisplay src/Main.cpp)
target_link_libraries(TerminalDisplay TerminalDisplaySources)