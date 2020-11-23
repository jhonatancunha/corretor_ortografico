#include <stdio.h>
#include <time.h>
#include "modules/dicionario/dict.h"
#include "modules/trie/trie.h"
#include "modules/corretor/corretor.h"

int main(int argc, char** argv){
  clock_t tempo;

  tempo = clock();
  ASCIITrie *dict = criarDicionario("modules/dicionario/dicionario.txt");

  char teste[] = "saladq";

  // if(argc != 2) analise = verificaArquivo(dict, "testes/default.txt");
  // else analise = verificaArquivo(dict, argv[1]);

  TAD_ANALISE *analise = verificaString(dict, teste);


  TAD_ImprimirAnalise(analise);

  AT_Destruir(dict);
  TAD_AnaliseDestruir(&analise);
  
  tempo = clock() - tempo;
  printf("Tempo de execucao -> %.2f segundos\n", ((float)tempo)/CLOCKS_PER_SEC);
  printf("=============================================================\n");
  return 0;
}
