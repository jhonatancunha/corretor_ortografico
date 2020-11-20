#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trie.h"

ASCIITrie *AT_Buscar_Iterativo(ASCIITrie *T, unsigned char *chave){
  if(T == NULL) return NULL;
  int x = strlen(chave);
  int i = 0;
  ASCIITrie **aux = &T;

  while(x != 0){
    if((*aux)->filhos[chave[i]-97] == NULL) return NULL;
    aux = &((*aux)->filhos[chave[i]-97]);
    i += 1;
    x--;
  }

  return (*aux);

}

static ASCIITrie *ASCIITrie_Buscar_Recursiva(ASCIITrie *T, unsigned char *chave, int tam, int p){
  if(T == NULL) return NULL; 
  if(p == tam) return T;
  return ASCIITrie_Buscar_Recursiva(T->filhos[chave[p]-97], chave, tam, p+1);
}

ASCIITrie *AT_Buscar(ASCIITrie *T, unsigned char *chave){
  return ASCIITrie_Buscar_Recursiva(T, chave, strlen(chave), 0);
}

ASCIITrie *AT_Criar(){
  ASCIITrie *no = malloc(sizeof(ASCIITrie));
  no->valor = 0;
  no->estado = TRIE_LIVRE;
  no->tamanho = 0;

  for(int i = 0; i < 26; i++) no->filhos[i] = NULL;

  return no;
}

static void AT_Inserir_Recursivo(ASCIITrie **T, unsigned char *chave, int valor, int tam, int p){
  if((*T) == NULL) *T = AT_Criar();

  if(p == tam){
    (*T)->valor = valor;
    (*T)->estado = TRIE_OCUPADO;
    return;
  }

  AT_Inserir_Recursivo(&(*T)->filhos[chave[p]-97], chave, valor, tam, p+1);
}

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int valor){
  AT_Inserir_Recursivo(T, chave, valor, strlen(chave), 0);
  (*T)->tamanho += 1;
}

void AT_Inserir_Iterativo(ASCIITrie **T, unsigned char *chave, int valor){
  if(*T == NULL) *T = AT_Criar();
  int x = strlen(chave);
  int i = 0;
  ASCIITrie **aux = T;

  while(x != 0){
    if((*aux)->filhos[chave[i]-97] == NULL) (*aux)->filhos[chave[i]-97] = AT_Criar();
    aux = &((*aux)->filhos[chave[i]-97]);
    i += 1;
    x--;
  }

  (*T)->tamanho += 1;
  (*aux)->estado = TRIE_OCUPADO;
  (*aux)->valor = valor;
}

void AT_Remover_Iterativo(ASCIITrie **T, unsigned char *chave){
  ASCIITrie ***removivel = calloc(strlen(chave), sizeof(ASCIITrie**));
  ASCIITrie **aux = T;
  int ligacoes = 0;
  int qtdRemovivel = 0;



  for(int i = 0; i < strlen(chave); i++){
    ligacoes = 0;
    if((*aux)->filhos[chave[i]-97] != NULL){
      for(int j = 0; j < 26; j++) if((*aux)->filhos[j] != NULL) ligacoes += 1;
      if(ligacoes == 1) removivel[qtdRemovivel++] = aux;
      aux = &((*aux)->filhos[chave[i]-97]);
    }
  }

  if(qtdRemovivel == 0) return;
  free(*aux);
  *aux = NULL;
  for(int x = 0; x < qtdRemovivel; x++){
    free(*(removivel[x]));
    *(removivel[x]) = NULL; 
  }
}

static void AT_Remover_Recursivo(ASCIITrie **T, unsigned char *chave, int tam, int p){
  if(*T == NULL) return;

  if(p == tam)
    (*T)->estado = TRIE_LIVRE;
  else
    AT_Remover_Recursivo(&(*T)->filhos[chave[p]-97], chave, tam, p+1);
  

  if((*T)->estado == TRIE_LIVRE){
    for(int i = 0; i < 26; i++) 
      if((*T)->filhos[i] != NULL) return;

    free(*T);
    *T = NULL;
  }
}

void AT_Remover(ASCIITrie **T, unsigned char *chave){
  AT_Remover_Recursivo(T, chave, strlen(chave), 0);
}

static void AT_Imprimir_Recursivo(ASCIITrie *T, unsigned char c, int nivel){
  if(T == NULL) return;
  
  for(int i = 0; i < nivel; i++) printf("-");
  char e = (T->estado == 0) ? 'L': 'O';
  printf("(%c) %d (%c)\n", c, T->valor, e);

  for(int i = 0; i < 26; i++)
    if(T->filhos[i] != NULL)
      AT_Imprimir_Recursivo(T->filhos[i], i+97, nivel+1);
}

void AT_Imprimir(ASCIITrie *T){
  AT_Imprimir_Recursivo(T, 0, 0);
}

static void AT_Destruir_R(ASCIITrie *T){
  if(T == NULL) return;

  for(int i = 0; i < 26; i++){
    if(T->filhos[i] != NULL){
      AT_Destruir_R(T->filhos[i]);
      T->filhos[i] = NULL;
    }
  }

  free(T);
}

void AT_Destruir(ASCIITrie *T){
  AT_Destruir_R(T);
}

