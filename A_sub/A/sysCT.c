#include <stdlib.h>
#include <stdio.h>
#include "sysCT.h"
#include <time.h> // using clock()

#define SUCESSO 1
#define FRACASSO 0

void imprime(void *p)
{
  //imprimeChar((pLDSE*) p);
}


int comparaDados(void *dado1, void *dado2)
{
  //printf("\n*Compara dados*");
  int n1 = *((int *)dado1);
  int n2 = *((int *)dado2);
  return n1 - n2;
}

void inputData (pLDSE ptr, char **argv) {
  
  char *bufrb = NULL;
  FILE *ptrfile = NULL;
  int total = 0;
  int cont  = 0;
  int valor = 0;
  char letra[4];

  bufrb = malloc(sizeof(char));
  while (bufrb!=NULL) {

    if (!fgets(letra, 4, stdin)) {
      //printf("\nWhile inserir - 1");
      // Entra aqui quando existe pulo de pagina ascii = 10(\n)
      if((insereArLis(ptr, &valor, comparaDados))){
         total++;
      }
      bufrb=NULL;
    } else {

      bufrb = &letra[0]; 
      // Adicionar função de conversao direta para char -> int

      valor = atoi(letra);

      //printf("\nWhile inserir - 2");
      if((insereArLis(ptr, &valor, comparaDados))){
          total++;
      }
  }}
  free(bufrb);
}

int main(int argc, char **argv){


  int op, numero,prior;
  //pArLis ptr;
  
  //vetor<*pLDSE> ptr;
  pLDSE ptr;

  //*ptr = (struct ArLis *)realloc(*ptr, 20);
  
  int novo;
  char remover[100];
  char buscar[100];

  FILE *ptrfile = NULL;
  char *word;
  size_t len=0;
  size_t read;


  if (argc < 1) {
    printf ("ERROR0: ./sysCT < filename \n");
    return 1;
  }

  //ppLDSE *pp = &ptr;
  //printf("\nMemoria ptr: %i", &ptr);
  //printf("\nMemoria pp: %i", &(*pp));

  //printf("\nAntes criar ArLis");
  if((criaLDSE(&(*(&ptr)), sizeof(int)))==FRACASSO) {
    printf("ERROR1\n");
    exit(1);
  }

 //printf("\n Teste null: %s", );
 inputData(ptr, argv);
 
  ptrfile = fopen("tools/words.map","rb");
  if (ptrfile==NULL) {
    printf("ERROR2\n");
    exit(1);
  }

  printf("Removing :");
  while ((read = getline(&word, &len, ptrfile)) != -1) {
    word[read-1] = '\0';
    strcpy(remover, word);
    if(removeArLis(&(*(&ptr)), &remover)){
      printf("(%s),", remover);
    } else {
      printf("(ERROR - %s)\n", remover);
    }
  }

  //printf("Tamanho vetor: %i", vector_size(ptr));

  printf("\n**************\n\n");
  imprimeChar(ptr);
  printf("\n**************\n");

  destroiArLis(ptr);
  return 0;
}
