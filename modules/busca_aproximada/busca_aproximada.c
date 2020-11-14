#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../trie/trie.h"
#include "../pilha/pilha.h"
#include "../lista/lista.h"

#define TAMANHO_ALFABETO 26

static ASCIITrie* TRIE_ObterPrefixo (ASCIITrie* T, unsigned char* prefixo, int tamanho, int passo) {
  if(T == NULL) return NULL; 
  if(passo == tamanho) return T;
  return TRIE_ObterPrefixo(T->filhos[prefixo[passo]-97], prefixo, tamanho, passo+1);
}

static void TRIE_EncontrarChavesComPrefixo (ASCIITrie* dicionario, LISTA* l, Pilha* p) {
  if (dicionario == NULL){
    Pilha_Remover(p);

    return;
  }

  if (dicionario->estado == TRIE_OCUPADO) {
    char* palavra_encontrada = calloc(strlen(p->vetor)+1, sizeof(char));
    memcpy(palavra_encontrada, p->vetor, p->prox);
    LISTA_Inserir(l, palavra_encontrada);
    Pilha_Remover(p);

    return;
  }

  for (int i = 0; i < TAMANHO_ALFABETO; i++){
    if (dicionario->filhos[i] != NULL) {
      Pilha_Inserir(p, i+97);
      TRIE_EncontrarChavesComPrefixo(dicionario->filhos[i], l, p);
    }
  }

  Pilha_Remover(p);
}

LISTA* TRIE_ChavesComPrefixo (ASCIITrie* dicionario, char* prefix) {
  Pilha* pilha_auxiliar = Pilha_Criar();
  LISTA* lista_palavras = LISTA_Criar();
  
  for (int i = 0; i < strlen(prefix); i++) {
    Pilha_Inserir(pilha_auxiliar, prefix[i]);
  }

  dicionario = TRIE_ObterPrefixo(dicionario, prefix, strlen(prefix), 0);
  TRIE_EncontrarChavesComPrefixo(dicionario, lista_palavras, pilha_auxiliar);

  Pilha_Destruir(pilha_auxiliar);

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
    for(int j = 0; j < 26; j++){
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

  Pilha_Destruir(p);

  return l;
}
