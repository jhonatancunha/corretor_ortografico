#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../lista/lista.h"
#include "dict.h"

ASCIITrie* criarDicionario(char *dicionario){
  FILE *arq = fopen(dicionario, "r");
  if(arq == NULL) return NULL;
  
  ASCIITrie *dict = NULL;
  char *string = calloc(LARGEST_WORD, sizeof(char));
  char c;
  int i = 0;

  do{
    c = fgetc(arq);
    if(c == '\n'){
      AT_Inserir(&dict, string, 1);
      i = 0;
      
      free(string);
      string = calloc(LARGEST_WORD, sizeof(char));
    }else{
      string[i++] = tolower(c);
    }
  }while(c != EOF);

  free(string);
  fclose(arq);

  return dict;
}
