#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha* Pilha_Criar () {
  Pilha* nova = malloc(sizeof(Pilha));
  nova->tamanho = 10;
  nova->vetor = calloc(nova->tamanho+1, sizeof(char));
  nova->prox = 0;

  return nova;
}

static void Pilha_Redimensionar (Pilha* pilha) {
  int novo_tamanho = pilha->tamanho + 10;
  char* novo_vetor = calloc(novo_tamanho+1, sizeof(char));
  
  for (int i = 0; i < pilha->tamanho; i++) {
    novo_vetor[i] = pilha->vetor[i];
  }

  free(pilha->vetor);
  pilha->vetor = novo_vetor;
  pilha->tamanho = novo_tamanho;
}

void Pilha_Inserir (Pilha* pilha, char c) {
  if (pilha->prox == pilha->tamanho) 
    Pilha_Redimensionar(pilha);
  
  pilha->vetor[pilha->prox++] = c;
}

void Pilha_Imprimir (Pilha* pilha) {
  printf("%s\n", pilha->vetor);
}

void Pilha_Remover (Pilha* pilha) {
  pilha->vetor[pilha->prox--];
}

void Pilha_Destruir (Pilha** pilha) {
  free((*pilha)->vetor);
  free(*pilha);
  *pilha = NULL;
}
