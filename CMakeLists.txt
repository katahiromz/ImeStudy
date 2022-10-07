# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.0)

# project name and languages
project(ImeStudyTools CXX)

# set output directory (build/)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

##############################################################################
# sub-directories

add_subdirectory(EnumLangIDs)
add_subdirectory(FocusCheck)
add_subdirectory(ImeWndTest)
add_subdirectory(IsImeTest)
add_subdirectory(KeyState)
add_subdirectory(KeybdList)
add_subdirectory(KeybdName)
add_subdirectory(LoadKeybd)
add_subdirectory(SysLang)
add_subdirectory(UserBreak)
add_subdirectory(UserLang)
add_subdirectory(WindowHierarchyChecker)

##############################################################################
