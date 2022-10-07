# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(ImeOnOffTest CXX)

##############################################################################

# ImeOnOffTest.exe
add_executable(ImeOnOffTest WIN32 ImeOnOffTest.cpp ImeOnOffTest_res.rc)
target_link_libraries(ImeOnOffTest PRIVATE comctl32 shlwapi imm32)
target_compile_definitions(ImeOnOffTest PRIVATE UNICODE _UNICODE)

##############################################################################
