#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
/**/
int checaSinal(char c){
    if (c == '+' || c == '-' || c == '/' || c == '*' )
        return 1;
    return 0; 
};

int analisaExpressao(tNo *no, int *result){
    int a , b;
    if (no != NULL)
    {
        if (checaSinal(no->valor)){
            a = (analisaExpressao(no->esq, result)); 
            b = (analisaExpressao(no->dir, result)); 
        }
        if (no->valor == '*'){
            printf("%d * %d ", a, b);
            (*result) =  a * b;
            printf("= %d \n", (*result));
            return ((*result));
        }
        else if (no->valor == '/'){
            printf("%d / %d ", a, b);
            (*result) =  a / b;
            printf("= %d \n", (*result));

            return ((*result));
        }
        else if (no->valor == '+'){
            printf("%d + %d ", a, b);
            (*result) = a + b;
            printf("= %d \n", (*result));
            return ((*result));
        }
        else if (no->valor == '-'){
            printf("%d - %d ", a, b);
            (*result) =  a-b;
            printf(" = %d \n", (*result));
            return ((*result));
        }
        else{
            return (no->valor - '0');
        } 
    }
    return (no->valor); 
};

