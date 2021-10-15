#include "estruturas.h"
#include "arvore-binaria.h"
#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

/*Função para inicialização do nó, com alocação de memória e atribuição de valores para os componentes do nó.*/
tNo *inicia(int valor)
{
    printf("VALOR: %d\n", valor); 
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->valor = valor;
    n->dir = NULL;
    n->esq = NULL;
    return n;
}

tNo *montaarvore(const char *str, int *i)
{
    tNo *no = NULL;
    if (str[*i] == '(')
    {   
        (*i)++; 
        // if next is not a number
        if (!(str[*i+1] >= 48 && str[*i+1] <= 57)) {
            no = inicia(str[*i]);
            (*i)++;
        
        }
        else {
            int k = 0;
            // int j = *i;
            char novoValor[50]; 
            for (int j = (*i);(str[j] >= 48 && str[j] <= 57);j++){
                k++;  
            } 
            strncpy(novoValor, &str[*i], k);
            // printf("antes : %c", str[*i]); 
            (*i) +=k;   
            // printf("depois : %c", str[*i]); 
            printf("NOVO VALOR : '%s' \n", novoValor); 
            no = inicia(atoi(novoValor)); 
        }
        no->esq = montaarvore(str, i);
        no->dir = montaarvore(str, i);
        (*i)++;
    }
    return no;
}

int contaNos(tNo *no)
{
    if (no != NULL)
    {
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    }
    else
        return 0;
}

void preordem(tNo *no)
{
    if (no != NULL)
    {
        printf("%c  ", no->valor);
        preordem(no->esq);
        preordem(no->dir);
    }
}

void emordem(tNo *no)
{
    if (no != NULL)
    {
        emordem(no->esq);
        printf("%c  ", no->valor);
        emordem(no->dir);
    }
}

void posordem(tNo *no)
{
    if (no != NULL)
    {
        posordem(no->esq);
        posordem(no->dir);
        printf("%c  ", no->valor);
    }
}


int altura(tNo *p)
{
    int he, hd;
    if (p == NULL)
        return -1;
    he = altura(p->esq);
    hd = altura(p->dir);
    if (he > hd)
        return he + 1;
    else
        return hd + 1;
}