all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	g++ Chapter12/Trees/BinaryTree.cpp -o ./Binaries/BinaryTree.o

execute:
	./Binaries/BinaryTree.o