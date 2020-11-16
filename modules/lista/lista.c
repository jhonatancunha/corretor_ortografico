#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA* LISTA_Criar () {
  LISTA* nova = malloc(sizeof(LISTA));
  nova->tamanho = 10;
  nova->vetor = malloc(sizeof(char*) * nova->tamanho);
  nova->quantidade_atual = 0;

  return nova;
}

static void LISTA_Redimensionar (LISTA* l) {
  int novo_tamanho = l->tamanho + 10;
  char** novo_vetor = malloc(sizeof(char*) * novo_tamanho);
  
  for (int i = 0; i < l->tamanho; i++) {
    novo_vetor[i] = l->vetor[i];
  }

  l->vetor = novo_vetor;
  l->tamanho = novo_tamanho;
}

void LISTA_Inserir (LISTA* l, char* palavra) {
  if (l->quantidade_atual == l->tamanho) 
    LISTA_Redimensionar(l);
  
  l->vetor[l->quantidade_atual++] = palavra;
}

int LISTA_isVazia (LISTA* l) { //refatoração: verificar se a lista realmente existe e retornar -1 caso não exista
  return l->quantidade_atual == 0 ? 1 : 0;
}

void LISTA_Imprimir (LISTA* l) {
  for (int i = 0; i < l->quantidade_atual; i++) {
    printf("%s\n", l->vetor[i]);
  }
}

void LISTA_Destruir (LISTA* l) {
  for (int i = 0; i < l->quantidade_atual; i++) {
    free(l->vetor[i]);  
  }

  free(l->vetor);
  free(l);
}
