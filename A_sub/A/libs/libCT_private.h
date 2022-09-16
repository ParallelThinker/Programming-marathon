#ifndef _ArLis_PRIVADO_H_
#define _ArLis_PRIVADO_H_

#include "libCT.h"
#include "LDSE.h"
#include <stdio.h>

/*typedef struct NoArLis{
    pLDSE lista;
    //struct NoArLis *proximo;
}NoArLis;*/



//typedef struct ArLis{
    //int tamInfo;
    //struct NoArLis *raiz;
    //struct NoArLis *fim;

//    int tamanho;
//    pLDSE bufLista;
//}ArLis;


int remove_recursivo(pLDSE *no, void *item);
void percorreArLis(pLDSE *pa);
int buscaPalArLis(pLDSE *pa, void *item);
void apagaNo(pLDSE *p);

#endif
