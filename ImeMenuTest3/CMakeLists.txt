# CMakeLists.txt --- CMake project settings
#    ex) cmake -G "Visual Studio 9 2008" .
#    ex) cmake -DCMAKE_BUILD_TYPE=Release -G "MSYS Makefiles" .
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 3.10)

# project name and languages
project(ImeMenuTest3 C RC)

# USE_CUSTOM option
option(USE_CUSTOM "Use custom menu" ON)
if(USE_CUSTOM)
    add_definitions(-DUSE_CUSTOM)
endif()

# USE_UNICODE option
option(USE_UNICODE "Use Unicode" ON)
if(USE_UNICODE)
    add_definitions(-DUNICODE -D_UNICODE)
endif()

# DO_TRANSPORT option
option(DO_TRANSPORT "Do transport" ON)
if(DO_TRANSPORT)
    add_definitions(-DDO_TRANSPORT)
endif()

# Show status
message(STATUS "USE_CUSTOM = ${USE_CUSTOM}")
message(STATUS "USE_UNICODE = ${USE_UNICODE}")
message(STATUS "DO_TRANSPORT = ${DO_TRANSPORT}")

##############################################################################

# ImeMenuTest3.exe
add_executable(ImeMenuTest3 WIN32
    ImeMenu.c
    ImeMenuTest3.c
    ImeMenuTest3_res.rc)
target_link_libraries(ImeMenuTest3 gdi32 comctl32 imm32 shlwapi)

##############################################################################
