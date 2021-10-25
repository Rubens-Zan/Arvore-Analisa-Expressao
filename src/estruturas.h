#ifndef _ESTRUTURAS_H_
#define _ESTRUTURAS_H_
#include <stdlib.h>

#define MAIS -111
#define MENOS -222
#define VEZES -333
#define DIVISAO -444

typedef struct tNo tNo;
struct tNo
{
    int valor; 
    tNo *esq, *dir;
};
#endif

