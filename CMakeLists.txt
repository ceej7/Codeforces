cmake_minimum_required( VERSION 3.12.0 ) # Latest version of CMake when this file was created.

add_executable( proj WIN32
 proj.cpp
)

set_target_properties(proj  PROPERTIES
LINK_FLAGS /SUBSYSTEM:CONSOLE
)

project( proj LANGUAGES CXX )