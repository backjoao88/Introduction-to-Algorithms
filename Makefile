all: clean compile execute

clean:
	rm -rf Binaries
	mkdir Binaries
compile:
	g++ Chapter18/b_tree.cpp -o Binaries/b_tree.o
execute:
	./Binaries/b_tree.o