#pragma once
#include "../trie/trie.h"

#define LARGEST_WORD 47

/* ESSA FUNÇÃO ACESSA UM ARQUIVO COM AS PALAVRAS DO DICIONÁRIO E RETORNA UMA
TRIE POPULADA COM TAIS PALAVRAS
*
*============ARGUMENTOS============
*dicionario = nome do arquivo que contem as palavras
*============RETORNO============
*return: ASCIITrie populada com as palavras corretas
*/
ASCIITrie* criarDicionario(char *dicionario);
