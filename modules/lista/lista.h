#pragma once

typedef struct LISTA {
  char** vetor;
  int tamanho;
  int quantidade_atual;
} LISTA;

LISTA* LISTA_Criar ();
void LISTA_Inserir (LISTA* l, char* palavra);
void LISTA_Remover (LISTA* l);
void LISTA_Imprimir (LISTA* l);
