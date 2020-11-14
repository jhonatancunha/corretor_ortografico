#include <string.h>
#include <stdlib.h>
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
