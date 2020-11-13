#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dict.h"

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

void CorrigirOrtografia(ASCIITrie* dicionario, char* texto){
  ASCIITrie *aux = AT_Buscar(dicionario, texto);
  if(aux == NULL) printf("%s nao encontrado!\n", texto);
  // else printf("%s encontrado!\n", texto);
}
