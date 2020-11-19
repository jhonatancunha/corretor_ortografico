#include <stdio.h>
#include "modules/dicionario/dict.h"
#include "modules/trie/trie.h"
#include "modules/corretor/corretor.h"

int main(int argc, char** argv){
  ASCIITrie *dict = criarDicionario("modules/dicionario/dicionario.txt");

  verificaArquivo(dict, "testes/casmurro2.txt");

  AT_Destruir(dict);
  return 0;
}
