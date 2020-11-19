#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../trie/trie.h"
#include "../pilha/pilha.h"
#include "../lista/lista.h"

#define TAMANHO_ALFABETO 26

static ASCIITrie* TRIE_ObterPrefixo (ASCIITrie* T, unsigned char* prefixo, int tamanho, int p) {
  if(T == NULL) return NULL; 
  if(p == tamanho) return T;
  return TRIE_ObterPrefixo(T->filhos[prefixo[p]-97], prefixo, tamanho, p+1);
}

static void TRIE_EncontrarChavesComPrefixo (ASCIITrie* dicionario, LISTA* lista_palavras, Pilha* pilha_auxiliar) {
  if (dicionario == NULL){
    Pilha_Remover(pilha_auxiliar);
    return;
  }

  if (dicionario->estado == TRIE_OCUPADO) {
    char* palavra_encontrada = calloc(strlen(pilha_auxiliar->vetor)+2, sizeof(char));
    memcpy(palavra_encontrada, pilha_auxiliar->vetor, pilha_auxiliar->prox);
    LISTA_Inserir(lista_palavras, palavra_encontrada);
  }

  for (int i = 0; i < TAMANHO_ALFABETO; i++){
    if (dicionario->filhos[i] != NULL) {
      Pilha_Inserir(pilha_auxiliar, i+97);
      TRIE_EncontrarChavesComPrefixo(dicionario->filhos[i], lista_palavras, pilha_auxiliar);
    }
  }

  Pilha_Remover(pilha_auxiliar);
}

LISTA* TRIE_ChavesComPrefixo (ASCIITrie* dicionario, char* prefix) {
  Pilha* pilha_auxiliar = Pilha_Criar();
  LISTA* lista_palavras = LISTA_Criar();

  dicionario = TRIE_ObterPrefixo(dicionario, prefix, strlen(prefix), 0);

  if (dicionario != NULL) {
    for (int i = 0; i < strlen(prefix); i++)
      Pilha_Inserir(pilha_auxiliar, prefix[i]);

    TRIE_EncontrarChavesComPrefixo(dicionario, lista_palavras, pilha_auxiliar);
  }

  Pilha_Destruir(&pilha_auxiliar);

  return lista_palavras;
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
    for(int j = 0; j < TAMANHO_ALFABETO; j++){
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

  free(string);
  Pilha_Destruir(&p);

  return l;
}

char* TRIE_ChaveMaiorPrefixoDe (ASCIITrie* T, char* s) {
  LISTA *prefixos = LISTA_Criar();
  ASCIITrie* TRIE_prefixo = NULL;
  char* prefixo;
  int contador = strlen(s) - 1;

  while (contador >= 0) {
    prefixo = calloc((strlen(s)-contador)+1, sizeof(char));
    memcpy(prefixo, s, (strlen(s)-contador));
    TRIE_prefixo = TRIE_ObterPrefixo(T, prefixo, strlen(prefixo), 0);

    if(TRIE_prefixo != NULL && TRIE_prefixo->estado == TRIE_OCUPADO) 
      LISTA_Inserir(prefixos, prefixo);
    else free(prefixo);
  
    contador--;
  }
  
  if(TRIE_prefixo != NULL) AT_Destruir(TRIE_prefixo);

  char *maior = LISTA_MaiorPalavra(prefixos);
  char *aux = NULL;
  if(maior != NULL){
    aux = calloc(strlen(maior)+1, sizeof(char));
    memcpy(aux, maior, strlen(maior));
  }
  
  LISTA_Destruir(&prefixos);

  return aux;
}
