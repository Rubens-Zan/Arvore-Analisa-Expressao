#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_
#include <stdlib.h>

typedef struct tNo tNo;
struct tNo
{
    int valor; // pode ser modificado para qualquer tipo de dado
    tNo *esq, *dir;
};

#endif

