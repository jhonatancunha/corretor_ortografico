#pragma once

typedef struct Pilha {
  char* vetor;
  int tamanho;
  int prox;
} Pilha;

Pilha* Pilha_Criar ();
void Pilha_Inserir (Pilha* l, char c);
void Pilha_Remover (Pilha* l);
void Pilha_Destruir (Pilha* l);
void Pilha_Imprimir (Pilha* l);
