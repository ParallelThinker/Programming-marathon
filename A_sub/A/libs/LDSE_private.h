
#include "LDSE.h"

typedef struct LDSE{
    struct NoLDSE *inicio;
    struct NoLDSE *fim;
    int tamanho_info;
    int tamanho_lista;
}LDSE;

typedef struct NoLDSE{
    void *dados;
    struct NoLDSE *proximo;
    int tipo;
}NoLDSE;
