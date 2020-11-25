#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "regras/regras.h"
#include "../dicionario/dict.h"
#include "corretor.h"
#include "../trie/busca_aproximada/busca_aproximada.h"

static int compare (const void * a, const void * b ) {
  const char *aux_a = *(char**)a;
  const char *aux_b = *(char**)b;
  
  return strlen(aux_b) - strlen(aux_a);
}

TAD_ANALISE* verificaString (ASCIITrie *dict, char *string) {
  TAD_ANALISE *analise = TAD_CriarAnalise(string);
  char *stringAux = calloc(LARGEST_WORD, sizeof(char));
    int i = 0;

  for(int j = 0; j <= strlen(string); j++){
    
    if(!isspace(string[j]) && !ispunct(string[j]) && string[j] != 0){
      stringAux[i++] = tolower(string[j]);
    }else{
      if(strlen(stringAux) > 0) CorrigirOrtografia(dict, stringAux, analise);

      free(stringAux);
      stringAux = calloc(LARGEST_WORD, sizeof(char));
      i = 0;
    }
  }
  free(stringAux);

  return analise;
}

TAD_ANALISE* verificaArquivo (ASCIITrie *dict, char *arquivo) {
  FILE *arq = fopen(arquivo, "r");
  if(arq == NULL) return NULL;

  char c;
  char *string;
  TAD_ANALISE *analise = TAD_CriarAnalise(arquivo);

  do{
    string = calloc(LARGEST_WORD, sizeof(char));
    int i = 0;
    while(1){
      c = fgetc(arq);
      if(isspace(c) || ispunct(c) || isdigit(c) || c == EOF) break;
      string[i++] = tolower(c);
    };

    if(i > 0) CorrigirOrtografia(dict, string, analise);
    
    free(string);
  }while(c != EOF);

  fclose(arq);
  return analise;
}

void Preenche_Trie_Sugestoes(ASCIITrie** trie,LISTA* l){
  for(int i = 0; i < l->quantidade_atual; i++){
    AT_Inserir(trie, l->vetor[i], 1);
  }
}

void CorrigirOrtografia(ASCIITrie* dicionario, char* texto, TAD_ANALISE *analise){
  analise->totalPalavras++;
  ASCIITrie *aux = AT_Buscar(dicionario, texto);

  if(aux == NULL){
    ASCIITrie *trie = NULL;

    printf("Palavra inexistente em dicionario fornecido: %s\n", texto);
    printf("Sugestoes:\n");

    // REGRA 1
    regra1_alterna_coringa(dicionario, &trie, texto, 0);

    // REGRA 2
    regra2_prefixo_grande(dicionario, &trie, texto);
  
    // REGRA 3
    regra3_maior_chave_de_prefixo(dicionario, &trie, texto);

    // REGRA 4
    regra4_coringa_no_prefixo_grande(dicionario, &trie, texto);

    // REGRA 5
    regra5_alternando_dois_coringas(dicionario, &trie, texto);

    // REGRA 6
    regra6_anulando_letras(dicionario, &trie, texto);

    LISTA *total = TRIE_ChavesComPrefixo(trie, "");
    qsort(total->vetor, total->quantidade_atual, sizeof(char*), compare);

    analise->qtdSugestoes +=  total->quantidade_atual;
    analise->qtdIncorretas++;

    AT_Destruir(trie);
    LISTA_Imprimir(total);
    LISTA_Destruir(&total);
  }
}

TAD_ANALISE* TAD_CriarAnalise(char *arq){
  TAD_ANALISE *tad = malloc(sizeof(TAD_ANALISE));
  tad->qtdIncorretas = 0;
  tad->qtdSugestoes = 0;
  tad->totalPalavras = 0;
  tad->arq = arq;

  return tad;
}

void TAD_AnaliseDestruir(TAD_ANALISE **tad){
  free(*tad);
  *tad = NULL;
}

void TAD_ImprimirAnalise(TAD_ANALISE *tad){
  printf("\n=============================================================\n");
  printf("\tDADOS OBTIDOS DURANTE A ANALISE DO ARQUIVO");
  printf("\n=============================================================\n");
  if(tad == NULL){
    printf("Arquivo de texto  inexistente, por favor informe um diretorio valido!\n");
    return;
  }
  
  printf("Arquivo aberto -> %s\n", tad->arq);
  printf("Total de palavras -> %d palavras\n", tad->totalPalavras);
  printf("Palavras incorretas -> %d palavras\n", tad->qtdIncorretas);
  printf("Media de sugestoes por palavras incorretas -> %.2f\n", (float)tad->qtdSugestoes/tad->qtdIncorretas);
}
