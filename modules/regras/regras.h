#pragma once
#include "../dicionario/dict.h"
#include "../trie/trie.h"
#include "../pilha/pilha.h"
#include "../busca_aproximada/busca_aproximada.h"

//REGRA 1
//ALTERNANDO CORIGNGA EX = *ATS - R*ATS- RA*S - RAT*
void regra_1_alterna_coringa(ASCIITrie *dict, ASCIITrie **trie, char *texto);

void regra2_prefixo_grande(ASCIITrie *dict, ASCIITrie **trie, char *texto);

void regra3_maior_chave_de_prefixo(ASCIITrie *dict, ASCIITrie **trie, char *texto);

void regra4_coringa_no_prefixo_grande (ASCIITrie *dict, ASCIITrie **trie, char* texto);
