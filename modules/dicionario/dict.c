#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dict.h"

#include "../regras/regras.h"

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
    regra1_alterna_coringa(dicionario, &trie, texto, 0);
  
    //REGRA 2
    regra2_prefixo_grande(dicionario, &trie, texto);

    //REGRA 3
    regra3_maior_chave_de_prefixo(dicionario, &trie, texto);

    //REGRA 4
    regra4_coringa_no_prefixo_grande(dicionario, &trie, texto);

    //REGRA 5
    regra5_alternando_dois_coringas(dicionario, &trie, texto);


    LISTA *total = TRIE_ChavesComPrefixo(trie, "");
    qsort(total->vetor, total->quantidade_atual, sizeof(char*), compare);

    AT_Destruir(trie);
    LISTA_Imprimir(total);
    LISTA_Destruir(&total);
    printf("\n\n");
  }
}

