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

static void ObterChavesQueCasam(LISTA *l, ASCIITrie *dict, Pilha *pilha, char *s, int p){
  if(dict == NULL){
    Pilha_Remover(pilha);
    return;
  }
  if(p == strlen(s)){
    if(dict->estado == TRIE_OCUPADO){
      char *aux = calloc(strlen(pilha->vetor)+1, sizeof(char));
      memcpy(aux, pilha->vetor, pilha->prox);
      LISTA_Inserir(l, aux);
    }
    Pilha_Remover(pilha);
    return;
  }

  if(ispunct(s[p])){
    for(int j = 0; j < 26; j++){
      if(dict->filhos[j] != NULL){
        Pilha_Inserir(pilha, j+97);
        ObterChavesQueCasam(l, dict->filhos[j], pilha, s, p+1);
      }
    }
  }else{
    Pilha_Inserir(pilha, s[p]);
    ObterChavesQueCasam(l, dict->filhos[s[p]-97], pilha, s, p+1);
  }

  Pilha_Remover(pilha);
}

LISTA* TRIE_ChavesQueCasam(ASCIITrie *dicionario, char* padrao, int n_extras){
  int tam = strlen(padrao)+n_extras;
  char *string = calloc(tam+1, sizeof(char));
  memset(string, '*', tam);
  memcpy(string, padrao, strlen(padrao));
  LISTA *l = LISTA_Criar();
  Pilha *p = Pilha_Criar();

  ObterChavesQueCasam(l, dicionario, p, string, 0);

  Pilha_Destruir(p);

  return l;
}
