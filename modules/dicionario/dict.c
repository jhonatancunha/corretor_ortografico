#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dict.h"

ASCIITrie* criarDicionario(){
  FILE *arq = fopen("modules/dicionario/dicionario.txt", "r");
  if(arq == NULL) return NULL;
  ASCIITrie *dict = NULL;
  char *string = calloc(LARGEST_WORD, sizeof(char));
  char aux;
  int i = 0;

  do{
    aux = fgetc(arq);
    if(aux == '\n'){
      AT_Inserir(&dict, string, 1);
      printf("%s\n", string);
      free(string);
      i = 0;
      string = calloc(LARGEST_WORD, sizeof(char));
    }else{
      string[i++] = tolower(aux);
    }
  }while(aux != EOF);

  free(string);
  fclose(arq);
}