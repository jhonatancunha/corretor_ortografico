#pragma once

#include "../trie.h"
#include "../../lista/lista.h"
#include "../../pilha/pilha.h"

LISTA* TRIE_ChavesComPrefixo (ASCIITrie* T, char* prefix);

LISTA* TRIE_ChavesQueCasam (ASCIITrie *dicionario, char* padrao, int n_extras);

char* TRIE_ChaveMaiorPrefixoDe (ASCIITrie* T, char* s);