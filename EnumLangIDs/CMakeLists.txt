# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(EnumLangIDs CXX)

##############################################################################

# EnumLangIDs.exe
add_executable(EnumLangIDs EnumLangIDs.cpp)
target_link_libraries(EnumLangIDs comctl32 shlwapi imm32)
target_compile_definitions(EnumLangIDs PRIVATE UNICODE _UNICODE)

##############################################################################
