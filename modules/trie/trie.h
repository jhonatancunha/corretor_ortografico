#pragma once

#define LARGEST_WORD 46

typedef enum ASCIITrie_Estado{
  TRIE_LIVRE,
  TRIE_OCUPADO
} ASCIITrie_Estado;

typedef struct ASCIITrie{
  int valor;
  int tamanho;
  struct ASCIITrie *filhos[26];
  ASCIITrie_Estado estado;
} ASCIITrie;


ASCIITrie *AT_Buscar(ASCIITrie *T, unsigned char *chave);
ASCIITrie *AT_Buscar_Iterativo(ASCIITrie *T, unsigned char *chave);

ASCIITrie *AT_Criar();

void AT_Inserir(ASCIITrie **T, unsigned char *chave, int valor);
void AT_Inserir_Iterativo(ASCIITrie **T, unsigned char *chave, int valor);

void AT_Remover(ASCIITrie **T, unsigned char *chave);
void AT_Remover_Iterativo(ASCIITrie **T, unsigned char *chave);

void AT_Imprimir(ASCIITrie *T);

