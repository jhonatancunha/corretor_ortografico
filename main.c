#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "modules/dicionario/dict.h"

void formataEntrada(ASCIITrie *dict, char *arquivo){
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

void formataEntradaString(ASCIITrie *dict, char *string){
  char aux;
  char *stringAux = calloc(LARGEST_WORD, sizeof(char));
  int i = 0, j;

  for(int j = 0; j <= strlen(string); j++){
    if(!isspace(string[j]) && !ispunct(string[j]) && string[j] != 0){
      stringAux[i++] = tolower(string[j]);
    }else{
      if(i > 0) CorrigirOrtografia(dict, stringAux);
      free(stringAux);
      stringAux = calloc(LARGEST_WORD, sizeof(char));
      i = 0;
    }
  }
  free(stringAux);
}

int main(int argc, char** argv){
  ASCIITrie *dict = criarDicionario("modules/dicionario/dicionario.txt");
  
  char string[] = "o rats roeu a roopa do rey de romi pois achov que era queejo";

  // formataEntradaString(dict, string);

  TRIE_ChavesQueCasam(dict, "ac", 2);
  // formataEntrada(dict, "testes/casmurro2.txt");
  return 0;
}
