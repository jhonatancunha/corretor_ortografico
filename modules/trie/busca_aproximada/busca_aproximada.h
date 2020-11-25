#pragma once

#include "../trie.h"
#include "../../lista/lista.h"

#define TAMANHO_ALFABETO 26

/*FUNÇÃO QUE BUSCA CHAVES QUE CONTENHAM DETERMINADO PREFIXO
*============ARGUMENTOS============
*T = arvore trie onde iremos buscar as chaves (o dicionario)
*prefix = prefixo a ser procurado
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

/*FUNÇÃO QUE BUSCA CHAVE QUE CONTÉM MAIOR QUANTIDADE DE CARACTERES DE UMA PALAVRA
*============ARGUMENTOS============
*T = arvore trie onde iremos buscar as chaves (dicionário)
*s = palavra da qual se buscará o maior prefixo 
*============RETORNO============
*return: string com o maior prefixo da palavra que é uma chave no dicionário
*/
char* TRIE_ChaveMaiorPrefixoDe (ASCIITrie* T, char* s);
