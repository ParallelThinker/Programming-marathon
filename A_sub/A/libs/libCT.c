#include <stdlib.h>
#include <string.h>
#include "libCT_private.h"

#define true 1
#define false 0

int criaArLis(ppLDSE p, int tamInfo)
{
  //(*p) = (pArLis)malloc(sizeof(ArLis));
  //if(p == NULL)
  //  return FRACASSO;

  //p[0].tamanho_info = tamInfo;
  //(*pp)->raiz = NULL;
  //(*pp)->fim = NULL;
  //printf("\nFuncao Criar Lista2");
  
  /*if(!criaLDSE((**p)->lista), sizeof(tamInfo))){
    return FRACASSO;
  }*/

  //printf("\nFuncao Criar Lista");
  //printf("\nFuncao Criar Lista4");

  return SUCESSO;
}

int reiniciaArLis(pLDSE p)
{
  if(p == NULL)
    return FRACASSO;
  //printf("\nFuncao reiniciar lista");

  apagaNo(&p);
  //p->raiz = NULL;
  //p->fim = NULL;
  return SUCESSO;
}

int destroiArLis(pLDSE pp)
{
  if(pp == NULL)
    return FRACASSO;

  //printf("\nFuncao destroi lista"); 
  //reiniciaArLis(*pp);
  
  /*if(!destroiLDSE(pp)){
    return FRACASSO;
  }*/
  
  free(pp);
  //free(&pp);
  pp = NULL;
  return SUCESSO;
}

int insereArLis(pLDSE p, void *novo, int (* cmp)(void *p1, void *p2))
{
  //printf("\nFuncao insere lista1");
  //if(p == NULL)
    //return FRACASSO;

  //printf("\nFuncao insere lista2");

  //Compara o caracter ascii com o espaço, se não
  int espaco = 32;
  if ((* cmp)(novo, &espaco)) {
    //printf("\nFuncao insere lista espaço");
  
    //Comparar o caractere ascii com o final, se não
    int final = 10;
    if ((*cmp)(novo, &final)) {
      //printf("\nFuncao insere lista ln");
      //Insere o elemento no fim da fila.

      //printf("\nFuncao insere letra, %s", novo);
      if(insereFim(p, novo)){
        return SUCESSO;
      } else {
        return FRACASSO;
      }
    }
  }

  //printf("\nFuncao insere espaco e final");
  //Se espaço ou final
  if(!insereFim(p, novo)){
    return FRACASSO;
  }


  //NoArLis *no = (NoArLis *)malloc(sizeof(NoArLis));
  //p
  //if(no == NULL)
  //  return FRACASSO;

  //no->lista = p->bufLista;

  //Cria uma struc dentro de p->bufLista
  
  /*printf("\nCaindo aqui");
  if(!criaLDSE(p, sizeof(int))){
    return FRACASSO;
  }*/

  //no->proximo = NULL;

  //if(p == NULL){
    //p[0] = no;
    //p->fim = no;
    //return SUCESSO;
  //}else{

    //NoLDSE aux = p[0];
    //no->proximo = NULL;
    //aux->proximo = no;
    //p->fim = no;
    
  //}
  
  return SUCESSO;
}

int removeArLis(pLDSE p, void *item) {
  if(p == NULL)
    return FRACASSO;

  //printf("\nFuncao remove lista");

  if (comparaLista2Palavra(p, item)== SUCESSO) {
    reiniciaLDSE(p);
    return SUCESSO;
  } else {
    return FRACASSO;
  }

  return FRACASSO;
}

int remove_recursivo(pLDSE *no, void *item) {

  /*if (no==NULL) {
    return FRACASSO;
  }

  int compara = comparaLista2Palavra(no, item);
  if (compara == SUCESSO) {
    reiniciaLDSE(no);
    return SUCESSO;
  } else {
    if (remove_recursivo(no->proximo, item)) {
      return SUCESSO;
    }

    return FRACASSO;
  }*/

  //printf("\nFuncao remove recursivo");
  //for(int i=0; i < vector_size(&no); i++)
  //{

    if (no==NULL)
      return FRACASSO;
    
    //pLDSE *aux = no[i];

    //printf("\nFuncao remove recursivo");

      int compara = comparaLista2Palavra(&no, item);

      if (compara == SUCESSO) {
        reiniciaLDSE(&no);
        return SUCESSO;
      }
    

    //if (compara == SUCESSO) {
    //  reiniciaLDSE(no);
    //  return SUCESSO;
    //}

    //printf("\n tamanho vetor %i", ((pLDSE*)no)[i]);
  //}

  return FRACASSO;
}

int buscaArLis(pLDSE p, void *item) {
  //NoArLis *aux;
  //aux = p->raiz;

  //printf("Funcao buscar lista");

  if(testaVaziaArLis(p))
    return FRACASSO;
  
  return buscaPalArLis(p, item);
}

int buscaPalArLis(pLDSE *pa, void *item) {
  /*if(pa != NULL){
    if (comparaLista2Palavra(pa, item)) {
      return SUCESSO;
    }
    if (buscaPalArLis(pa->proximo,item)) {
      return SUCESSO;
    }
  }*/

  //printf("\nFuncao bucar Palabra ArLis");

  //for(int i=0; i<vector_size(pa); i++)
  //{
    if(pa != NULL)
      if (comparaLista2Palavra(&pa, item)) {
        return SUCESSO;
      }
  //}

  return FRACASSO;
}

int testaVaziaArLis(pLDSE p)
{

  //printf("\nFuncao testa lista vazia");
  if(p == NULL)
    return FRACASSO;

  //if(p->raiz == NULL)
  //  return SUCESSO;
  else
    return FRACASSO;
}

int percursoArLis(pLDSE pa) {
  if(testaVaziaArLis(pa))
    return FRACASSO;
  
  //printf("\n Lista nao vazia");
  printf("\n");
  //processa(pa);
  //percorreArLis(pa, (* processa));
  
  return SUCESSO;
}

void percorreArLis(pLDSE *pa) {
  /*if(pa != NULL){
    if (pa->proximo != NULL) {
      processa(pa->proximo->lista);
      
      percorreArLis(pa->proximo,(* processa));
    }
  }*/

  //for(int i=0; i < vector_size(pa); i++)
  //{
  //  printf("\n Funcao percorre lista %i", i);

    if(pa != NULL){
      //if (pa->inicio != NULL) {
        //processa(pa);
      
        //percorreArLis(((pLDSE*)pa)[i],(* processa));
      //}
    //}
  }


}

void apagaNo(pLDSE *p)
{
  /*if(p != NULL){
    apagaNo(p->proximo);
    free(p);
  }*/
  /*printf("\nFuncao apagaNo");
  for(int i=0; i< vector_size(p); i++)
  {
    //free(p[i]);
  }*/
}
