#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "modules/dicionario/dict.h"
// #include "modules/trie/trie.h"


void formataEntrada(char *arquivo){
  FILE *arq = fopen(arquivo, "r");
  char aux;
  char *string;
  int i;

  do{
    string = calloc(LARGEST_WORD, sizeof(char));
    i = 0;
    while(1){
      aux = fgetc(arq);
      if(isspace(aux) || ispunct(aux) || aux == EOF) break;
      string[i++] = tolower(aux);
    };
    printf("%s\n", string);
    free(string);
  }while(aux != EOF);
}

void formataEntradaString(char *string){
  char aux;
  char *stringAux = calloc(LARGEST_WORD, sizeof(char));
  int i = 0, j;

  for(int j = 0; j <= strlen(string); j++){
    if(!isspace(string[j]) && !ispunct(string[j]) && string[j] != 0){
      stringAux[i++] = tolower(string[j]);
    }else{
      printf("%s\n", stringAux);
      free(stringAux);
      stringAux = calloc(LARGEST_WORD, sizeof(char));
      i = 0;
    }
  }
  free(stringAux);
}


int main(int argc, char** argv){
  ASCIITrie *dict = criarDicionario();

  return 0;
}
