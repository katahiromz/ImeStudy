g++ -c -o hello8.o hello8.cpp
windres -i hello8_res.rc -o hello8_res.o
g++ -mwindows -o hello8 hello8.o hello8_res.o
