#include "LDSE.h"
#ifndef _ArLis_INTERFACE_H_
#define _ArLis_INTERFACE_H_

#define SUCESSO 1
#define FRACASSO 0

//typedef struct ArLis *pArLis, **ppArLis;

int criaArLis(ppLDSE pp, int tamInfo);
int destroiArLis(pLDSE pp);
int reiniciaArLis(pLDSE p);
int insereArLis(pLDSE p, void *novo, int (* cmp)(void *p1, void *p2));
int buscaArLis(pLDSE p, void *item);
int removeArLis(pLDSE p, void *item);
int testaVaziaArLis(pLDSE p);
int percursoArLis(pLDSE pa);

#endif
