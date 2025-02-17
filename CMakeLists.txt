cmake_minimum_required(VERSION 3.10)
project(SecuritySystemGUI)

set(CMAKE_CXX_STANDARD 17)

# Find the SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

add_executable(SecuritySystemGUI main.cpp)

target_link_libraries(SecuritySystemGUI sfml-system sfml-window sfml-graphics)
