all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	g++ Chapter12/12.1-4.cpp -o Binaries/12.1-4.o
execute:
	./Binaries/12.1-4.o