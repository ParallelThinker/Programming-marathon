#include "LDSE_private.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include  <omp.h>

/*-------------------------------------------------------------------------*/
int criaLDSE(ppLDSE pp, int tamanho_info)
{
	//printf("\nFuncao Criar Lista");
	(*pp) = (LDSE *)malloc(sizeof(LDSE));
    if( pp == NULL)
    	return FRACASSO;

	//printf("\nFuncao Criar Lista4");
	(*pp)->tamanho_info = tamanho_info;
	(*pp)->inicio = NULL;
	(*pp)->fim = NULL;
	(*pp)->tamanho_lista = 0;

	return SUCESSO;
}

/*-------------------------------------------------------------------------*/
int destroiLDSE(ppLDSE pp)
{
	if( (*pp) == NULL)
		return FRACASSO;

	reiniciaLDSE((*pp));
	free((*pp));
	(*pp) = NULL;

	return SUCESSO;
}

/*-------------------------------------------------------------------------*/
int reiniciaLDSE(pLDSE p)
{
	NoLDSE *aux, *prox;

	if(p == NULL)
		return FRACASSO;

	aux = p->inicio;
	while(aux != NULL){
		prox = aux->proximo;
		free(aux->dados);
		free(aux);
		aux = prox;
	}

	p->inicio = NULL;
	p->fim = NULL;
	p->tamanho_lista = 0;

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int testaVazia(pLDSE p)
{
	if(p == NULL)
		return FRACASSO;
	
	//printf("\nTestaVazia, %s", &p->inicio);
	if(p->inicio == NULL)
	{
		//printf("\nVazia");
		return SUCESSO;
	}
	else
	{
		//printf("\nLista cheia");
		return FRACASSO;
	}

}


/*-------------------------------------------------------------------------*/
int contaElementos(pLDSE p)
{
	/*if(p == NULL)
		return FRACASSO;

	int n = 0;
	NoLDSE *aux = p->inicio;

	while(aux != NULL){
		aux = aux->proximo;
		n++;
	}*/

	return 0;
}


/*-------------------------------------------------------------------------*/
int insereInicio(pLDSE p, void *elemento)
{
	//printf("\nInsere Inicio, elemento: %i", &p->tamanho_info);

	NoLDSE *novo;

	/*if(p == NULL)
		return FRACASSO;
	*/
	//printf("\nInserir dados p!= null");

	novo = (NoLDSE *)malloc(sizeof(NoLDSE));
	if(novo == NULL)
		return FRACASSO;
	novo->dados = (void *)malloc(&p->tamanho_info);
	if(novo->dados == NULL){
		free(novo);
		return FRACASSO;
	}

	//printf("Dados inseridos: %i", elemento);
	memcpy(novo->dados, elemento, p->tamanho_info);
	novo->proximo = NULL;

	novo->proximo = NULL;
	p->inicio = novo;
	p->fim = novo;
	p->tamanho_lista++;

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int insereFim(pLDSE p, void *elemento)
{
	NoLDSE *novo;

	//printf("\nDados inseridos:");

	//if(p == NULL)
	//	return FRACASSO;
	if(testaVazia(p))
		return insereInicio(p, elemento);
		

	novo = (NoLDSE *)malloc(sizeof(NoLDSE));
	if(novo == NULL)
		return FRACASSO;
	
	novo->dados = (void *)malloc(p->tamanho_info);

	if(novo->dados == NULL){
		free(novo);
		return FRACASSO;
	}
	
	memcpy(novo->dados, elemento, p->tamanho_info);
	novo->proximo = NULL;

	novo->proximo = NULL;
	p->fim->proximo = novo;
	p->fim = novo;
	p->tamanho_lista++;

	//printf("\Dado inserido: %s", &p->inicio->dados);

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int inserePosicao(pLDSE p, int N, void *elemento)
{
	/*NoLDSE *aux, *anterior, *novo;
	int n;

	if(p == NULL)
		return FRACASSO;
	if(N > contaElementos(p))
		return insereFim(p, elemento);
	if(testaVazia(p) || N == 1)
		return insereInicio(p, elemento);

	novo = (NoLDSE *)malloc(sizeof(NoLDSE));
	if(novo == NULL)
		return FRACASSO;
	novo->dados = (void *)malloc(p->tamanho_info);
	if(novo->dados == NULL){
		free(novo);
		return FRACASSO;
	}
	memcpy(novo->dados, elemento, p->tamanho_info);
	novo->proximo = NULL;

	anterior = p->inicio;
	aux = anterior->proximo;
	n = 2;
	while(n < N){
		anterior = aux;
		aux = aux->proximo;
		n++;
	}

	anterior->proximo = novo;
	novo->proximo = aux;*/

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int removeInicio(pLDSE p, void *elemento)
{
	NoLDSE *aux;

	if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;

	aux = p->inicio;
	memcpy(elemento, aux->dados, p->tamanho_info);
	p->inicio = aux->proximo;
	free(aux->dados);
	free(aux);
	p->tamanho_lista--;

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int removeFim(pLDSE p, void *elemento)
{
	/*NoLDSE *aux, *anterior;

	if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;
	if(contaElementos(p) == 1)
		return removeInicio(p, elemento);

	anterior = p->inicio;
	aux = anterior->proximo;
	while(aux->proximo != NULL){
		anterior = aux;
		aux = aux->proximo;
	}

	memcpy(elemento, aux->dados, p->tamanho_info);
	free(aux->dados);
	free(aux);
	anterior->proximo = NULL;*/

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int removePosicao(pLDSE p, int N, void *elemento)
{
	/*NoLDSE *aux, *anterior;
	int n;

	if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;

	n = contaElementos(p);
	if(N > n)
		return FRACASSO;
	if(N == n)
		return removeFim(p, elemento);
	if(N == 1)
		return removeInicio(p, elemento);

	anterior = p->inicio;
	aux = anterior->proximo;
	n = 2;
	while(n < N){
		anterior = aux;
		aux = aux->proximo;
		n++;
	}

	memcpy(elemento, aux->dados, p->tamanho_info);
	anterior->proximo = aux->proximo;
	free(aux->dados);
	free(aux);*/

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int buscaInicio(pLDSE p, void *elemento)
{
	/*if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;

	memcpy(elemento, p->inicio->dados, p->tamanho_info);*/

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int buscaFim(pLDSE p, void *elemento)
{
	/*NoLDSE *fim;

	if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;

	fim = p->fim;

	memcpy(elemento, fim->dados, p->tamanho_info);
*/
	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
int buscaPosicao(pLDSE p, int N, void *elemento)
{
	/*NoLDSE *aux;
	int n;

	if(p == NULL)
		return FRACASSO;
	n = contaElementos(p);
	if(N > n || n == 0)
		return FRACASSO;

	aux = p->inicio;
	n = 1;
	while(n < N){
		aux = aux->proximo;
		n++;
	}
	memcpy(elemento, aux->dados, p->tamanho_info);*/

	return SUCESSO;
}


/*-------------------------------------------------------------------------*/
void imprimeInt(pLDSE p)
{
	/*NoLDSE *aux;
	int elemento, i;

	if(p == NULL)
		return;
	if(testaVazia(p))
		return;

	aux = p->inicio;

	while(aux != NULL){
        memcpy(&elemento, aux->dados, p->tamanho_info);
		printf("%i ", elemento);
		aux = aux->proximo;
	}

	#pragma omp for 
	for(i=0; i <= p->tamanho_lista; i++)
	{
		memcpy(&elemento, aux->dados, p->tamanho_info);
		printf("%i ", elemento);
	}*/

	return;
}

/*-------------------------------------------------------------------------*/
void imprimeChar(pLDSE p)
{
	NoLDSE *aux;
	int elemento, i;

	if(p == NULL)
		return;
	if(testaVazia(p))
		return;

	//printf("LDSE: imprimeChar --> ");

	aux = p->inicio;

	//printf("Dados lista: %i", aux->tipo);
	while(aux != NULL){
        memcpy(&elemento, aux->dados, p->tamanho_info);
		printf("%c", elemento);
		aux = aux->proximo;
	}

	/*#pragma omp for 
	for(i=0; i < p->tamanho_lista; i++)
	{
		memcpy(&elemento, aux->dados, p->tamanho_info);
		printf("%c", elemento);
		aux = aux->proximo;
	}*/

	return;
}

/*-------------------------------------------------------------------------*/
int comparaLista2Palavra(pLDSE p, char *palavra)
{
	NoLDSE *aux;
	int elemento;
	int ct=0;
	int flag=0;
	int flag2=0;

	int nlista = &p->tamanho_lista;
	//printf("\n * Palavra: %i", nlista);

	if(p == NULL)
		return FRACASSO;
	if(testaVazia(p))
		return FRACASSO;

	aux = p->inicio;

	while(aux != NULL){

		if ((*((char*)aux->dados) >= 33) && (*((char*)aux->dados) < 123)) {

			if (*((char*)aux->dados) == palavra[ct]) {
				flag++;
				flag2++;
			}
		}
		
		ct++;
		aux = aux->proximo;
	}

	//printf("\n Flag: %i", flag);

	

	if ((flag == nlista-1) && (flag2) && (flag == strlen(palavra))) {
	   return SUCESSO;
	} else {
		return FRACASSO;
	}

	return FRACASSO;
}



