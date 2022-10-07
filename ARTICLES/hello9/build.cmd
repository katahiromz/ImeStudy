g++ -c -o hello9.o hello9.cpp
windres -i hello9_res.rc -o hello9_res.o
g++ -mwindows -o hello9 hello9.o hello9_res.o
