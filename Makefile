all: clean compile execute

clean: 
	rm -rf Binaries/*
compile:
	g++ 10.1-1.cpp -o Binaries/10.1-1.o
	g++ 10.1-2.cpp -o Binaries/10.1-2.o
	g++ 10.1-3.cpp -o Binaries/10.1-3.o
	# g++ 10.1-6.cpp -o Binaries/10.1-6.o
	g++ 10.4-2.cpp -o Binaries/10.4-2.o
	g++ 10.4-3.cpp -o Binaries/10.4-3.o
	g++ 10.4-4.cpp -o Binaries/10.4-4.o
	g++ 10.2-1.cpp -o Binaries/10.2-1.o
	g++ 10.2-5.cpp -o Binaries/10.2-5.o
	g++ BinaryTree/treeTest.cpp BinaryTree/Tree.h -o Binaries/treeTest.o
execute:
	# ./Binaries/10.1-1.o
	# ./Binaries/10.1-2.o
	# ./Binaries/10.1-3.o
	# ./Binaries/10.1-6.o
	# ./Binaries/10.2-1.o
	./Binaries/10.2-5.o
	# ./Binaries/10.4-2.o
	# ./Binaries/10.4-3.o
	# ./Binaries/10.4-4.o
	
	