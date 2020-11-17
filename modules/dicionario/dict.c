#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dict.h"
#include "../pilha/pilha.h"
#include "../busca_aproximada/busca_aproximada.h"

static int compare (const void * a, const void * b ) {
    const char *aux_a = *(char**)a;
    const char *aux_b = *(char**)b;
    
    return strlen(aux_b) - strlen(aux_a);
}

ASCIITrie* criarDicionario(char *dicionario){
  FILE *arq = fopen(dicionario, "r");
  if(arq == NULL) return NULL;
  ASCIITrie *dict = NULL;
  char *string = calloc(LARGEST_WORD, sizeof(char));
  char aux;
  int i = 0;

  do{
    aux = fgetc(arq);
    if(aux == '\n'){
      AT_Inserir(&dict, string, 1);
      free(string);
      i = 0;
      string = calloc(LARGEST_WORD, sizeof(char));
    }else{
      string[i++] = tolower(aux);
    }
  }while(aux != EOF);

  free(string);
  fclose(arq);

  return dict;
}

void Preenche_Trie_Sugestoes(ASCIITrie** trie,LISTA* l){
  for(int i = 0; i < l->quantidade_atual; i++){
    AT_Inserir(trie, l->vetor[i], 1);
  }
}

void CorrigirOrtografia(ASCIITrie* dicionario, char* texto){
  ASCIITrie *aux = AT_Buscar(dicionario, texto);
  if(aux == NULL){
    ASCIITrie *trie = NULL;

    printf("palavra nao esta no dicionario: %s\n", texto);
    printf("sugestoes:\n");

    //REGRA 1
    //ALTERNANDO CORIGNGA EX = *ATS - R*ATS- RA*S - RAT*
    char *padrao = calloc(strlen(texto)+1, sizeof(char));
    memcpy(padrao, texto, strlen(texto));
    for(int i = 0; i < strlen(padrao); i++){
      char antes = padrao[i];
      padrao[i] = '*';
      LISTA *l_coringa = TRIE_ChavesQueCasam(dicionario, padrao, 0);
      padrao[i] = antes;

      Preenche_Trie_Sugestoes(&trie, l_coringa);
      LISTA_Destruir(l_coringa);
    }
    free(padrao);
  
    //REGRA 2
    if(strlen(texto) > 5){
      char *caso1 = calloc(strlen(texto), sizeof(char));
      char *caso2 = calloc(strlen(texto)-1, sizeof(char));

      memcpy(caso1, texto, strlen(texto)-1);
      LISTA *l1 = TRIE_ChavesComPrefixo(dicionario, caso1);
 
      memcpy(caso2, texto, strlen(texto)-2);
      LISTA *l2 = TRIE_ChavesComPrefixo(dicionario, caso2);

      free(caso1);
      free(caso2);

      Preenche_Trie_Sugestoes(&trie, l1);
      Preenche_Trie_Sugestoes(&trie, l2);
      LISTA_Destruir(l1);
      LISTA_Destruir(l2);
    }


    //REGRA 3
    char* chave_maior_prefixo = TRIE_ChaveMaiorPrefixoDe(dicionario, texto);
    if(strlen(chave_maior_prefixo) > 0) AT_Inserir(&trie, chave_maior_prefixo, 1);

    LISTA *total = TRIE_ChavesComPrefixo(trie, "");
    qsort(total->vetor, total->quantidade_atual, sizeof(char*), compare);

    // free(chave_maior_prefixo);
    AT_Destruir(trie);
    LISTA_Imprimir(total);
    // LISTA_Destruir(total);
    printf("\n\n");
  }
}

