#include <stdio.h>
#include <time.h>
#include "modules/dicionario/dict.h"
#include "modules/trie/trie.h"
#include "modules/corretor/corretor.h"

int main(int argc, char** argv){
  clock_t tempo;

  tempo = clock();
  ASCIITrie *dict = criarDicionario("modules/dicionario/dicionario.txt");

  char arq[] = "testes/casmurro2.txt";
  TAD_ANALISE *analise = verificaArquivo(dict, arq);

  printf("\n=============================================================\n");
  printf("\tDADOS OBTIDOS DURANTE A ANALISE DO ARQUIVO");
  printf("\n=============================================================\n");
  printf("Arquivo aberto -> %s\n", arq);
  printf("Total de palavras -> %d palavras\n", analise->totalPalavras);
  printf("Palavras incorretas -> %d palavras\n", analise->qtdIncorretas);
  printf("Media de sugestoes por palavras incorretas -> %.2f\n", (float)analise->qtdSugestoes/analise->qtdIncorretas);

  AT_Destruir(dict);
  TAD_AnaliseDestruir(&analise);
  
  tempo = clock() - tempo;
  printf("Tempo de execucao -> %.2f segundos\n", ((float)tempo)/CLOCKS_PER_SEC);
  printf("=============================================================\n");
  return 0;
}
