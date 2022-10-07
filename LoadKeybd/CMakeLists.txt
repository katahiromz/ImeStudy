# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(LoadKeybd CXX)

##############################################################################

# LoadKeybd.exe
add_executable(LoadKeybd LoadKeybd.cpp)
target_link_libraries(LoadKeybd comctl32 shlwapi imm32)
target_compile_definitions(LoadKeybd PRIVATE UNICODE _UNICODE)

##############################################################################
