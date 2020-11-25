#pragma once
#include "../../trie/trie.h"

#define CORINGA '*'

//REGRA 1
//ALTERNANDO CORIGNGA EX = *ATS - R*ATS- RA*S - RAT*
void regra1_alterna_coringa(ASCIITrie *dict, ASCIITrie **trie, char *texto, int n_extras);

void regra2_prefixo_grande(ASCIITrie *dict, ASCIITrie **trie, char *texto);

void regra3_maior_chave_de_prefixo(ASCIITrie *dict, ASCIITrie **trie, char *texto);

void regra4_coringa_no_prefixo_grande (ASCIITrie *dict, ASCIITrie **trie, char* texto);

void regra5_alternando_dois_coringas(ASCIITrie *dict, ASCIITrie **trie, char* texto);

void regra6_anulando_letras (ASCIITrie *dict, ASCIITrie **trie, char* texto);
