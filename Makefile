all:
	gcc -g -c main.c
	gcc -g -c modules/trie/trie.c
	gcc -o main *.o
	