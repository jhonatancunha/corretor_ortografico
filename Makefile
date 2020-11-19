all:
	gcc -g -c main.c
	gcc -g -c modules/lista/lista.c
	gcc -g -c modules/pilha/pilha.c
	gcc -g -c modules/trie/trie.c
	gcc -g -c modules/trie/busca_aproximada/busca_aproximada.c
	gcc -g -c modules/dicionario/dict.c
	gcc -g -c modules/regras/regras.c
	gcc -g -c modules/corretor/corretor.c
	gcc -o main *.o
	