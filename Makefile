all:
	gcc -g -c main.c
	gcc -g -c modules/lista/lista.c
	gcc -g -c modules/trie/trie.c
	gcc -g -c modules/dicionario/dict.c
	gcc -o main *.o
	