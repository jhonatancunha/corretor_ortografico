#pragma once 

#include "../trie/trie.h"
#include "../lista/lista.h"


typedef struct TAD_ANALISE{
  int totalPalavras;
  int qtdIncorretas;
  int qtdSugestoes;
  char *arq;
}TAD_ANALISE;

/*FUNÇÃO QUE CRIA TAD DE ANALISE DE RESULTADOS
*============ARGUMENTOS============
*arq = arquivo analisado
*============RETORNO============
*return: TAD_ANALISE criado
*/
TAD_ANALISE* TAD_CriarAnalise(char *arq);

/*FUNÇÃO QUE DESTROI TAD DE ANALISE DE RESULTADOS
*============ARGUMENTOS============
*tad = endereço da TAD que ira ser destruida
*============RETORNO============
*return: void
*/
void TAD_AnaliseDestruir(TAD_ANALISE **tad);

/*FUNÇÃO QUE CRIA TAD DE ANALISE DE RESULTADOS
*============ARGUMENTOS============
*arq = arquivo analisado
*============RETORNO============
*return: TAD_ANALISE criado
*/
void TAD_ImprimirAnalise(TAD_ANALISE *tad);

/*FUNÇÃO QUE VERIFICA STRING A SER CORRIGIDA
*============ARGUMENTOS============
*dict = dicionario com as palavras corretas
*string = string que desejamos analisar ortografia
*============RETORNO============
*return: TAD_ANALISE obtido
*/
TAD_ANALISE* verificaString (ASCIITrie *dict, char *string);

/*FUNÇÃO QUE VERIFICA ARQUIVO .TXT A SER CORRIGIDO
*============ARGUMENTOS============
*dict = dicionario com as palavras corretas
*arquivo = string que desejamos analisar ortografia
*============RETORNO============
*return: TAD_ANALISE obtido
*/
TAD_ANALISE* verificaArquivo (ASCIITrie *dict, char *arquivo);

/*FUNÇÃO QUE CORRIGE ORTOGRAFIA DE TEXTO
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*texto = texto que desejamos corrigir a ortografia
*analise = TAD onde iremos inserir dados obtidos durante o processo
*============RETORNO============
*return: void
*/
void CorrigirOrtografia(ASCIITrie* dicionario, char* texto, TAD_ANALISE *analise);

/*FUNÇÃO QUE PREENCHE TRIE AUXILIAR DE CADA PALAVRA INCORRETA
*============ARGUMENTOS============
*trie = endereço da trie que iremos inserir as palavras
*l = lista que contém palavras a serem inseridas na trie
*============RETORNO============
*return: void
*/
void Preenche_Trie_Sugestoes(ASCIITrie** trie, LISTA* l);
