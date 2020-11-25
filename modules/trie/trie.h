#pragma once

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


/*FUNÇÃO BUSCA CHAVE NA TRIE DE MANEIRA RECURSIVA
*============ARGUMENTOS============
*T = arvore trie onde iremos buscar a chave
*chave = chave a ser procurada
*============RETORNO============
*return: NULL caso chave não exista
*return: endereço ASCIITrie da chave se existir
*/
ASCIITrie *AT_Buscar(ASCIITrie *T, unsigned char *chave);

/*FUNÇÃO QUE CRIA ARVORE TRIE
*============RETORNO============
*return: endereço ASCIITrie criado
*/
ASCIITrie *AT_Criar();

/*FUNÇÃO QUE INSERE CHAVE COM DETERMINADO VALOR NA TRIE
*============ARGUMENTOS============
*T = arvore trie onde iremos inserir a chave
*chave = chave a ser inserida
*valor = valor referente a chave inserida
*============RETORNO============
*return: void
*/
void AT_Inserir(ASCIITrie **T, unsigned char *chave, int valor);

/*FUNÇÃO QUE REMOVE CHAVE DA ARVORE TRIE
*============ARGUMENTOS============
*T = arvore trie onde iremos remover a chave
*chave = chave a ser removida
*============RETORNO============
*return: void
*/
void AT_Remover(ASCIITrie **T, unsigned char *chave);

/*FUNÇÃO QUE DESTROI ARVORE TRIE
*============ARGUMENTOS============
*T = arvore trie que deseja destruir
*============RETORNO============
*return: void
*/
void AT_Destruir(ASCIITrie *T);
