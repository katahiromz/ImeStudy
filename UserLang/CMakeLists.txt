# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(UserLang CXX)

##############################################################################

# UserLang.exe
add_executable(UserLang UserLang.cpp)
target_link_libraries(UserLang comctl32 shlwapi imm32)
target_compile_definitions(UserLang PRIVATE UNICODE _UNICODE)

##############################################################################
