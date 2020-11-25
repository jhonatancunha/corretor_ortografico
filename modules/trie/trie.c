#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "trie.h"

static ASCIITrie *ASCIITrie_Buscar_Recursiva(ASCIITrie *T, unsigned char *chave, int tam, int p){
  if(T == NULL) return NULL; 
  if(p == tam) return T;
  return ASCIITrie_Buscar_Recursiva(T->filhos[chave[p]-97], chave, tam, p+1);
}

static void AT_Inserir_Recursivo(ASCIITrie **T, unsigned char *chave, int valor, int tam, int p){
  if((*T) == NULL) *T = AT_Criar();

  if(p == tam){
    (*T)->valor = valor;
    (*T)->estado = TRIE_OCUPADO;
    return;
  }

  AT_Inserir_Recursivo(&(*T)->filhos[chave[p]-97], chave, valor, tam, p+1);
}

static void AT_Remover_Recursivo(ASCIITrie **T, unsigned char *chave, int tam, int p){
  if(*T == NULL) return;

  if(p == tam)
    (*T)->estado = TRIE_LIVRE;
  else
    AT_Remover_Recursivo(&(*T)->filhos[chave[p]-97], chave, tam, p+1);
  

  if((*T)->estado == TRIE_LIVRE){
    for(int i = 0; i < 26; i++) 
      if((*T)->filhos[i] != NULL) return;

    free(*T);
    *T = NULL;
  }
}

ASCIITrie *AT_Buscar(ASCIITrie *T, unsigned char *chave){
  return ASCIITrie_Buscar_Recursiva(T, chave, strlen(chave), 0);
}

ASCIITrie *AT_Criar(){
  ASCIITrie *no = malloc(sizeof(ASCIITrie));
  no->valor = 0;
  no->estado = TRIE_LIVRE;
  no->tamanho = 0;

  for(int i = 0; i < 26; i++) no->filhos[i] = NULL;

  return no;
}

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int valor){
  AT_Inserir_Recursivo(T, chave, valor, strlen(chave), 0);
  (*T)->tamanho += 1;
}

void AT_Remover(ASCIITrie **T, unsigned char *chave){
  AT_Remover_Recursivo(T, chave, strlen(chave), 0);
}

void AT_Destruir(ASCIITrie *T){
  AT_Destruir_R(T);
}
