all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	g++ Chapter2/2.3-6.cpp -o Binaries/2.3-6.o

execute:
	./Binaries/2.3-6.o