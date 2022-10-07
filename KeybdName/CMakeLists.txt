# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(KeybdName CXX)

##############################################################################

# KeybdName.exe
add_executable(KeybdName KeybdName.cpp)
target_link_libraries(KeybdName comctl32 shlwapi imm32)
target_compile_definitions(KeybdName PRIVATE UNICODE _UNICODE)

##############################################################################
