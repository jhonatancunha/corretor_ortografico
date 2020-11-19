#pragma once 

#include "../trie/trie.h"
#include "../lista/lista.h"
#include "regras/regras.h"

typedef struct TAD_ANALISE{
  int totalPalavras;
  int qtdIncorretas;
  int qtdSugestoes;
  char *arq;
}TAD_ANALISE;

TAD_ANALISE* TAD_CriarAnalise(char *arq);
void TAD_AnaliseDestruir(TAD_ANALISE **tad);
void TAD_ImprimirAnalise(TAD_ANALISE *tad);

void verificaString (ASCIITrie *dict, char *string);
TAD_ANALISE* verificaArquivo (ASCIITrie *dict, char *arquivo);
void CorrigirOrtografia(ASCIITrie* dicionario, char* texto, TAD_ANALISE *analise);
void Preenche_Trie_Sugestoes(ASCIITrie** trie, LISTA* l);
