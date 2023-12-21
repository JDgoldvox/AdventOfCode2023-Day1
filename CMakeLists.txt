# CMakeList.txt: CMake project for Trebuchet, include source and define
# project-specific logic here.

cmake_minimum_required(VERSION 3.8)

# Project Name
project("Trebuchet")

# Enable Hot Reload for MSVC compilers if supported.
if(POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
endif()
set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")

# Add source to this project's executable.
add_executable(Trebuchet-Part1 "Trebuchet-Part1.cpp")
add_executable(Trebuchet-Part2 "Trebuchet-Part2.cpp")

# Set C++ standard
set_property(TARGET Trebuchet-Part1 PROPERTY CXX_STANDARD 20)
set_property(TARGET Trebuchet-Part2 PROPERTY CXX_STANDARD 20)

# TODO: Add tests and install targets if needed.