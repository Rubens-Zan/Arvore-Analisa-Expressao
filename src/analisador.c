#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
/* -------------------------------------------------------------------------- */
int ehSinal(int v){
    return (v == MAIS || v == MENOS || v == DIVISAO || v == VEZES );
};
/* -------------------------------------------------------------------------- */
int analisaExpressao(tNo *no, int *result){
    int a , b;
    if (no != NULL)
    {
        if (ehSinal(no->valor)){
            a = (analisaExpressao(no->esq, result)); 
            b = (analisaExpressao(no->dir, result)); 
            if (no->valor == VEZES){
                printf("%d * %d ", a, b);
                (*result) =  a * b;
                printf("= %d \n", (*result));
                return ((*result));
            }
            else if (no->valor == DIVISAO){
                printf("%d / %d ", a, b);
                (*result) =  a / b;
                printf("= %d \n", (*result));
                return ((*result));
            }
            else if (no->valor == MAIS){
                printf("%d + %d ", a, b);
                (*result) = a + b;
                printf("= %d \n", (*result));
                return ((*result));
            }
            else if (no->valor == MENOS){
                printf("%d - %d ", a, b);
                (*result) =  a-b;
                printf(" = %d \n", (*result));
                return ((*result));
            }
        }
        else{
            return (no->valor);
        } 
    }
    return (no->valor); 
};