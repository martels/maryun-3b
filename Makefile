main: dictionary.o grid.o main.o
	g++ dictionary.o grid.o main.o -o main

dictionary.o: dictionary.cpp
	g++ -Wall -c dictionary.cpp

grid.o: grid.cpp
	g++ -Wall -c grid.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o main dictionary.o
