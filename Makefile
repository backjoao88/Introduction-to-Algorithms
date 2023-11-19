all: clean compile execute

clean:
	rm -rf Binaries
	mkdir Binaries
compile:
	g++ Chapter13/avl_tree.cpp -o Binaries/avl_tree.o
execute:
	./Binaries/avl_tree.o