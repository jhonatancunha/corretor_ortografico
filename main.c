#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LARGEST_WORD 46

void formataEntrada(char *arquivo){
  // for (int i = 0; i < strlen(string); i++) string[i] = tolower(string[i]);
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

int main(int argc, char** argv){
  // char string[] = "OLA ESTE E UM TESTE SE NOSSA FUNCAO ESTA FUNCIONANDO CORRETAMENTE";


  // printf("INICIO: %s\n", string);  
  formataEntrada("testes/casmurro1.txt");
  // printf("FIM: %s\n", string);

  // for(int i = 0; i < 256; i++){
  //   printf("%c - %d\n", i, i);
  // }

  return 0;
}
