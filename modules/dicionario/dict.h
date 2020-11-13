#pragma once
#include "../trie/trie.h"

ASCIITrie* criarDicionario(char *dicionario);

void CorrigirOrtografia(ASCIITrie* dicionario, char* texto);