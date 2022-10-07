g++ -c -o hello5.o hello5.cpp
windres -i hello5_res.rc -o hello5_res.o
g++ -mwindows -o hello5 hello5.o hello5_res.o
