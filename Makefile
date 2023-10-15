all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	g++ Chapter2/2.3-8.cpp -o Binaries/2.3-8.o
execute:
	./Binaries/2.3-8.o