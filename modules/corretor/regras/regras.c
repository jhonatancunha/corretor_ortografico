#include <stdlib.h>
#include <string.h>
#include "regras.h"

void regra1_alterna_coringa (ASCIITrie *dict, ASCIITrie **trie, char *texto, int n_extras) {
  char *prefixo = calloc(strlen(texto)+1, sizeof(char));
  memcpy(prefixo, texto, strlen(texto));
  
  for(int i = 0; i < strlen(prefixo); i++){
    char caracter = prefixo[i];
    prefixo[i] = CORINGA;
    LISTA *l_coringa = TRIE_ChavesQueCasam(dict, prefixo, n_extras);
    prefixo[i] = caracter;

    Preenche_Trie_Sugestoes(trie, l_coringa);
    LISTA_Destruir(&l_coringa);
  }
  free(prefixo);
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
  if(strlen(texto) <= 4) return;
  
  char *prefixo = calloc(strlen(texto)+1, sizeof(char));
  memcpy(prefixo, texto, strlen(texto));

  char c1;
  char c2;

  for(int i = 0; i < strlen(prefixo); i++){
    c1 = prefixo[i];
    for(int j = i+1; j < strlen(prefixo); j++){
      c2 = prefixo[j];
      
      prefixo[i] = CORINGA;
      prefixo[j] = CORINGA;
      LISTA *l_coringa = TRIE_ChavesQueCasam(dict, prefixo, 0);

      prefixo[i] = c1;
      prefixo[j] = c2;

      Preenche_Trie_Sugestoes(trie, l_coringa);
      LISTA_Destruir(&l_coringa);
    }
  }
  free(prefixo);
}

void regra6_anulando_letras (ASCIITrie *dict, ASCIITrie **trie, char* texto) {
  int i_nulo = 0;
  int j = 0;

  for(int c = 0; c < strlen(texto); c++){
    char *prefixo = calloc(strlen(texto), sizeof(char));
  
    for(int i = 0; i < strlen(texto); i++) 
      if(i != i_nulo) prefixo[j++] = texto[i];
    
    LISTA *lista = TRIE_ChavesQueCasam(dict, prefixo, 0);
    Preenche_Trie_Sugestoes(trie, lista);
    LISTA_Destruir(&lista);
    free(prefixo);

    i_nulo++;
    j=0;
  }
}
