#pragma once

typedef struct Pilha {
  char* vetor;
  int tamanho;
  int prox;
} Pilha;


/* FUNÇÃO QUE CRIA UMA PILHA
*
*============RETORNO============
*return: endereço da pilha criada
*/
Pilha* Pilha_Criar ();

/* FUNÇÃO QUE INSERE UM CARACTER NA PILHA
*
*============ARGUMENTOS============
* l = endereço da pilha
* c = caracter a ser inserido
*============RETORNO============
*return: void
*/
void Pilha_Inserir (Pilha* pilha, char c);

/* FUNÇÃO QUE REMOVE O CARACTER DO TOPO DA PILHA
*
*============ARGUMENTOS============
* l = endereço da pilha
*============RETORNO============
*return: void
*/
void Pilha_Remover (Pilha* pilha);

/* FUNÇÃO QUE DESTRÓI TOTALMENTE A PILHA
*
*============ARGUMENTOS============
* l = ponteiro de ponteiro de PILHA
*============RETORNO============
*return: void
*/
void Pilha_Destruir (Pilha** pilha);

/* FUNÇÃO QUE IMPRIME O CONTEÚDO DA PILHA
*
*============ARGUMENTOS============
* l = endereço da pilha
*============RETORNO============
*return: void
*/
void Pilha_Imprimir (Pilha* pilha);
