#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "corretor.h"
#include "../regras/regras.h"

static int compare (const void * a, const void * b ) {
  const char *aux_a = *(char**)a;
  const char *aux_b = *(char**)b;
  
  return strlen(aux_b) - strlen(aux_a);
}

void verificaString (ASCIITrie *dict, char *string) {
  char aux;
  char *stringAux = calloc(LARGEST_WORD, sizeof(char));
  int i = 0, j;

  for(int j = 0; j <= strlen(string); j++){
    if(!isspace(string[j]) && !ispunct(string[j]) && string[j] != 0){
      stringAux[i++] = tolower(string[j]);
    }else{
      if(i > 0) {
        CorrigirOrtografia(dict, stringAux);
      }
      free(stringAux);
      stringAux = calloc(LARGEST_WORD, sizeof(char));
      i = 0;
    }
  }
  free(stringAux);
}

void verificaArquivo (ASCIITrie *dict, char *arquivo) {
  FILE *arq = fopen(arquivo, "r");
  char aux;
  char *string;
  int qtdpalavras = 0;
  int i;

  do{
    string = calloc(LARGEST_WORD, sizeof(char));
    i = 0;
    while(1){
      aux = fgetc(arq);
      if(isspace(aux) || ispunct(aux) || isdigit(aux) || aux == EOF) break;
      string[i++] = tolower(aux);
    };

    if(i > 0) {
      CorrigirOrtografia(dict, string);
      qtdpalavras += 1;
    }
    free(string);
  }while(aux != EOF);

  printf("\n\n%d palavras verificadas!\n", qtdpalavras);
  fclose(arq);
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
    regra1_alterna_coringa(dicionario, &trie, texto, 0);
  
    //REGRA 2
    regra2_prefixo_grande(dicionario, &trie, texto);

    //REGRA 3
    regra3_maior_chave_de_prefixo(dicionario, &trie, texto);

    //REGRA 4
    regra4_coringa_no_prefixo_grande(dicionario, &trie, texto);

    //REGRA 5
    regra5_alternando_dois_coringas(dicionario, &trie, texto);

    regra6_anulando_letras(dicionario, &trie, texto);

    LISTA *total = TRIE_ChavesComPrefixo(trie, "");
    qsort(total->vetor, total->quantidade_atual, sizeof(char*), compare);

    AT_Destruir(trie);
    LISTA_Imprimir(total);
    LISTA_Destruir(&total);
    printf("\n\n");
  }
}
