#pragma once 

#include "../trie/trie.h"
#include "../lista/lista.h"
#include "regras/regras.h"

void verificaString (ASCIITrie *dict, char *string);
void verificaArquivo (ASCIITrie *dict, char *arquivo);
void CorrigirOrtografia(ASCIITrie* dicionario, char* texto);
void Preenche_Trie_Sugestoes(ASCIITrie** trie, LISTA* l);