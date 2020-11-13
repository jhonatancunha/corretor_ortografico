#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA* LISTA_Criar () {
  LISTA* nova = malloc(sizeof(LISTA));
  nova->vetor = malloc(sizeof(char*) * 1);
  nova->tamanho = 1;
  nova->quantidade_atual = 0;

  return nova;
}

static void LISTA_Redimensionar (LISTA* l) {
  char** novo_vetor = malloc(sizeof(char*) * (l->tamanho + 10));
  
  for (int i = 0; i < l->tamanho; i++) {
    novo_vetor[i] = l->vetor[i];
  }

  l->vetor = novo_vetor;
}

void LISTA_Inserir (LISTA* l, char* palavra) {
  if (l->quantidade_atual == l->tamanho) 
    LISTA_Redimensionar(l);
  
  l->vetor[l->quantidade_atual++] = palavra;
}

void LISTA_Imprimir (LISTA* l) {
  for (int i = 0; i < l->quantidade_atual; i++) {
    printf("%s\n", l->vetor[i]);
  }

  printf("\nquantidade atual: %d\n", l->quantidade_atual);
}

void LISTA_Remover (LISTA* l) {
  free(l->vetor);
  free(l);
}
