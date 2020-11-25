#pragma once

typedef struct LISTA {
  char** vetor;
  int tamanho;
  int quantidade_atual;
} LISTA;

/* FUNÇÃO QUE CRIA UMA LISTA
*
*============RETORNO============
*return: endereço da lista criada
*/
LISTA* LISTA_Criar ();

/* FUNÇÃO QUE INSERE UMA STRING NA LISTA
*
*============ARGUMENTOS============
* l = endereço da lista
* palavra = string que será inserida
*============RETORNO============
*return: void
*/
void LISTA_Inserir (LISTA* l, char* palavra);

/* FUNÇÃO QUE VERIFICA SE A LISTA ESTÁ VAZIA OU NÃO
*
*============ARGUMENTOS============
* l = endereço da lista
*============RETORNO============
*return: 1 caso esteja vazia e 0 caso contrário
*/
int LISTA_isVazia (LISTA* l);

/* FUNÇÃO QUE RETORNA A MAIOR PALAVRA DA LISTA
*
*============ARGUMENTOS============
* l = endereço da lista
*============RETORNO============
*return: string com a maior palavra
*/
char* LISTA_MaiorPalavra (LISTA* l);

/* FUNÇÃO QUE IMPRIME AS PALAVRAS DA LISTA
*
*============ARGUMENTOS============
* l = endereço da lista
*============RETORNO============
*return: void
*/
void LISTA_Imprimir (LISTA* l);

/* FUNÇÃO QUE DESTRÓI TOTALMENTE A LISTA
*
*============ARGUMENTOS============
* l = ponteiro de ponteiro de LISTA
*============RETORNO============
*return: void
*/
void LISTA_Destruir (LISTA** l);
