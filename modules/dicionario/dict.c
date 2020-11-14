#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dict.h"
#include "../pilha/pilha.h"

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

// strict void ObterChavesQueCasam(LISTA *l, ASCIITrie *dict, Pilha *p, char *s, int p){
//   if(p == len(s)){
//     LISTA_Inserir(l, s);
//     return;
//   }

//   if(ispunct(s[i])){
//     for(int j = 0; j < 26; j++){
//       if(dict->filhos[j] != NULL){
//         Pilha_Inserir(p, s[p]);
//         ObterChavesQueCasam(Ll, dict, s, p+1);
//       }
//     }
//   }else{
//     Pilha_Inserir(p, s[p]);
//     ObterChavesQueCasam(Ll, dict, s, p+1);
//   }

//   Pilha_Remover(p);
// }


// LISTA* TRIE_ChavesQueCasam(ASCIITrie *dicionario, char* padrao, int n_extras){
//   int tam = strlen(padrao)+n_extras;
//   char *string = calloc(tam+1, sizeof(char));
//   memset(string, '*', tam);
//   memcpy(string, padrao, strlen(padrao));
//   LISTA *l = LISTA_Criar();
//   Pilha *p = Pilha_Criar();

//   ObterChavesQueCasam(l, dicionario, p, string, 0);
// }
