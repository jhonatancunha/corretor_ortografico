#pragma once
#include "../trie/trie.h"
#include "../lista/lista.h"

ASCIITrie* criarDicionario(char *dicionario);

void CorrigirOrtografia(ASCIITrie* dicionario, char* texto);

LISTA* TRIE_ChavesQueCasam(ASCIITrie *dicionario, char* padrao, int n_extras);