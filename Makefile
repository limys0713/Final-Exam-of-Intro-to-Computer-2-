main: Cube.o Cuboid.o Block.o main.o
	g++ -o main Cube.o Cuboid.o Block.o main.o

main.o: Block.h Cube.h Cuboid.h main.cpp
	g++ -c main.cpp

Cube.o: Cube.h Cube.cpp
	g++ -c Cube.cpp

Cuboid.o: Cuboid.h Cuboid.cpp
	g++ -c Cuboid.cpp

Block.o: Block.h Block.cpp
	g++ -c Block.cpp


clean: 
	rm main *.o