#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

void formataEntrada(char *string){
  for (int i = 0; i < strlen(string); i++){
    string[i] = tolower(string[i]);
    switch ((int)string[i]){
      case 224 ... 229:
        string[i] = 'a';
        break;
      case 232 ... 235:
        string[i] = 'e';
        break;
      case 236 ... 239:
        string[i] = 'i';
        break;
      case 242 ... 246:
        string[i] = 'o';
        break;
      case 249 ... 252:
        string[i] = 'u';
        break;
    }  
  }
}

int main(int argc, char** argv){
  setlocale(LC_ALL, "");
  char string[] = "OLÁ ESTE É UM TESTE SE NOSSA FUNÇÃO ESTÁ FUNCIONANDO CORRETAMENTE";


  printf("INICIO: %s\n", string);  
  formataEntrada(string);
  printf("FIM: %s\n", string);


  return 0;
}
