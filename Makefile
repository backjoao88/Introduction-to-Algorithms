all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	# g++ Chapter2/2.1-3.cpp -o Binaries/2.1-3.o
	# g++ Chapter2/2.1-4.cpp -o Binaries/2.1-4.o
	g++ Chapter2/2.1-5.cpp -o Binaries/2.1-5.o

execute:
	# ./Binaries/2.1-3.o
	# ./Binaries/2.1-4.o
	./Binaries/2.1-5.o
