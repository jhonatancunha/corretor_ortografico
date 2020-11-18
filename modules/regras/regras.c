#include "regras.h"
#include <stdlib.h>
#include <string.h>

void regra1_alterna_coringa (ASCIITrie *dict, ASCIITrie **trie, char *texto, int n_extras) {
  char *padrao = calloc(strlen(texto)+1, sizeof(char));
  memcpy(padrao, texto, strlen(texto));
  
  for(int i = 0; i < strlen(padrao); i++){
    char antes = padrao[i];
    padrao[i] = '*';
    LISTA *l_coringa = TRIE_ChavesQueCasam(dict, padrao, n_extras);
    padrao[i] = antes;

    Preenche_Trie_Sugestoes(trie, l_coringa);
    LISTA_Destruir(&l_coringa);
  }
  free(padrao);
}

void regra2_prefixo_grande (ASCIITrie *dict, ASCIITrie **trie, char *texto) {
  if(strlen(texto) > 5){
    char *caso1 = calloc(strlen(texto), sizeof(char));
    char *caso2 = calloc(strlen(texto)-1, sizeof(char));

    memcpy(caso1, texto, strlen(texto)-1);
    LISTA *l1 = TRIE_ChavesComPrefixo(dict, caso1);
 
    memcpy(caso2, texto, strlen(texto)-2);
    LISTA *l2 = TRIE_ChavesComPrefixo(dict, caso2);

    free(caso1);
    free(caso2);

    Preenche_Trie_Sugestoes(trie, l1);
    Preenche_Trie_Sugestoes(trie, l2);
    LISTA_Destruir(&l1);
    LISTA_Destruir(&l2);
  }
}

void regra3_maior_chave_de_prefixo (ASCIITrie *dict, ASCIITrie **trie, char *texto) {
  char* chave_maior_prefixo = TRIE_ChaveMaiorPrefixoDe(dict, texto);

  if(chave_maior_prefixo != NULL){
    AT_Inserir(trie, chave_maior_prefixo, 1);
    free(chave_maior_prefixo);
  }
}

void regra4_coringa_no_prefixo_grande (ASCIITrie *dict, ASCIITrie **trie, char* texto) {
  if(strlen(texto) > 5){
    char *caso1 = calloc(strlen(texto), sizeof(char));
    char *caso2 = calloc(strlen(texto)-1, sizeof(char));

    memcpy(caso1, texto, strlen(texto)-1);
    regra1_alterna_coringa(dict, trie, caso1, 0);

    memcpy(caso2, texto, strlen(texto)-2);
    regra1_alterna_coringa(dict, trie, caso2, 2);

    free(caso1);
    free(caso2);
  }
}

void regra5_alternando_dois_coringas(ASCIITrie *dict, ASCIITrie **trie, char* texto){
  if(strlen(texto) < 4) return;
  
  char *string = calloc(strlen(texto)+1, sizeof(char));
  memcpy(string, texto, strlen(texto));

  char aux1;
  char aux2;

  for(int i = 0; i < strlen(string); i++){
    aux1 = string[i];
    for(int j = i+1; j < strlen(string); j++){
      aux2 = string[j];
      
      string[i] = '*';
      string[j] = '*';
      LISTA *l_coringa = TRIE_ChavesQueCasam(dict, string, 0);

      string[i] = aux1;
      string[j] = aux2;

      Preenche_Trie_Sugestoes(trie, l_coringa);
      LISTA_Destruir(&l_coringa);
    }
  }
  free(string);
}