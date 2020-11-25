#pragma once
#include "../../trie/trie.h"

#define CORINGA '*'

/*REGRA 1 - UTILIZAREMOS A TÉCNICA DE ALTERNAR CORINGAS COM OBJETIVO DE 
ENCONTRAR QUAL A LETRA INCORRETA EM NOSSA PALAVRA. CORINGAS SERÃO REPRESENTADOS 
PELO CARACTER '*', E NA POSIÇÃO REFERENTE A ELE, PODEMOS USAR QUALQUER LETRA DO 
ALFABETO ATÉ ENCONTRAR A CORRETA
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra1_alterna_coringa(ASCIITrie *dict, ASCIITrie **trie, char *texto, int n_extras);

/*REGRA 2 - UTILIZAREMOS EM PALAVRAS COM MAIS DE 5 LETRAS, ONDE IREMOS PESQUISAR 
UMA PALAVRA P QUE VÁ ATÉ A POSIÇÃO N-3 E N-2. TAL REGRA NOS RETORNA CHAVES QUE 
CASAM COM O PREFIXO PROCURADO  
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra2_prefixo_grande(ASCIITrie *dict, ASCIITrie **trie, char *texto);

/*REGRA 3 - ESTA REGRA RETORNA O MAIOR PREFIXO VÁLIDO DE UMA PALAVRA PROCURADA. 
A FIM DE EXEMPLO, AO PESQUISAR A PALAVRA "ZEBRAOLHO", RECEBEREMOS A CHAVE 
"ZEBRA" COMO RETORNO 
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra3_maior_chave_de_prefixo(ASCIITrie *dict, ASCIITrie **trie, char *texto);

/*REGRA 4 - ESSA REGRA É FORMULADA VIA CONJUNÇÃO DA REGRA 1 COM A REGRA 2,
 OU SEJA, APLICAREMOS A REGRA 2 NA PALAVRA ALVO E LOGO APÓS A REGRA 1 
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra4_coringa_no_prefixo_grande (ASCIITrie *dict, ASCIITrie **trie, char* texto);

/*REGRA 5 - ESSA REGRA É FORMULADA VIA CONJUNÇÃO DA REGRA 1 COM A REGRA 2, 
OU SEJA, APLICAREMOS A REGRA 2 NA PALAVRA ALVO E LOGO APÓS A REGRA 1 
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra5_alternando_dois_coringas(ASCIITrie *dict, ASCIITrie **trie, char* texto);

/*REGRA 6 - ESSA REGRA FOI PENSADA PARA ENCONTRAR PALAVRAS QUE CONTÉM LETRAS 
REPETIDAS OU INEXISTENTES, A MESMA INTERCALA PELOS CARACTERES DA PALAVRAS ANULANDO-OS 
*============ARGUMENTOS============
*dicionario = dicionario com as palavras corretas
*trie = endereço da trie onde iremos inserir sugestões de palavras
*texto = texto a ser analisado
*n_extras = quantidade de caracteres extras que iremos considerar no final do texto
*============RETORNO============
*return: void
*/
void regra6_anulando_letras (ASCIITrie *dict, ASCIITrie **trie, char* texto);
