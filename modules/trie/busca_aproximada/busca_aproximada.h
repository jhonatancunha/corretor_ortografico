#pragma once

#include "../trie.h"
#include "../../lista/lista.h"

#define TAMANHO_ALFABETO 26

/*FUNÇÃO QUE BUSCA CHAVES QUE CONTENHAM DETERMINADO PREFIXO
*============ARGUMENTOS============
*T = arvore trie onde iremos buscar as chaves
*prefix = prefix a ser procurado
*============RETORNO============
*return: LISTA que contém todas as chaves encontradas
*/
LISTA* TRIE_ChavesComPrefixo (ASCIITrie* T, char* prefix);

/*FUNÇÃO QUE BUSCA CHAVES QUE CASAM COM DETERMINADO PREFIXO
*============ARGUMENTOS============
*dicionario = dicionario onde iremos procurar as chaves
*padrao = prefixo que iremos procurar em nosso dicionario
*n_extras = quantidade de caracteres extras que podemos considerar durante a consulta
*============RETORNO============
*return: LISTA que contém todas as chaves encontradas
*/
LISTA* TRIE_ChavesQueCasam (ASCIITrie *dicionario, char* padrao, int n_extras);

/*FUNÇÃO QUE BUSCA CHAVE QUE CONTÉM MAIOR QUANTIDADE DE CARACTERES
DE UM PREFIXO
*============ARGUMENTOS============
*T = arvore trie onde iremos buscar as chaves
*prefix = prefix a ser procurado
*============RETORNO============
*return: string que contém o prefixo desejado
*/
char* TRIE_ChaveMaiorPrefixoDe (ASCIITrie* T, char* s);
