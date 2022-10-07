g++ -c -o hello4.o hello4.cpp
windres -i hello4_res.rc -o hello4_res.o
g++ -mwindows -o hello4 hello4.o hello4_res.o
