all: clean compile execute

clean:
	rm -rf Binaries/*
compile:
	# g++ Chapter12/Trees/test_binary_tree.cpp  -o Binaries/test_binary_tree.o
	g++ Chapter12/12.2-7.cpp -o Binaries/12.2-7.o
execute:
	./Binaries/12.2-7.o