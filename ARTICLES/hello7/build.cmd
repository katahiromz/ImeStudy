g++ -c -o hello7.o hello7.cpp
windres -i hello7_res.rc -o hello7_res.o
g++ -mwindows -o hello7 hello7.o hello7_res.o
