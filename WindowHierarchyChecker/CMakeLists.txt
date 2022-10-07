# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(whc CXX)

##############################################################################

# whc.exe
add_executable(whc whc.cpp)
target_link_libraries(whc comctl32 shlwapi imm32)
target_compile_definitions(whc PRIVATE UNICODE _UNICODE)

##############################################################################
