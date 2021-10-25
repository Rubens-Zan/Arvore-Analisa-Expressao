#include "estruturas.h"
#include "arvore-binaria.h"
#include <stdio.h>
#include <string.h>

/* -------------------------------------------------------------------------- */
int checaSinal(const char *c){
    if ((*c) == '+')
        return MAIS;
    if ((*c) == '-')
        return MENOS;
    if ((*c) == '/')
        return DIVISAO;
    if ((*c) == '*')
        return VEZES;
    return 0; 
};
/* -------------------------------------------------------------------------- */
tNo *inicia(const char *valor)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    int sinal = checaSinal(valor); 
    if (sinal){
        n->valor = sinal; 
    }
    else {
        n->valor = atoi(valor);
    }
    n->dir = NULL;
    n->esq = NULL;
    return n;
}
/* -------------------------------------------------------------------------- */
tNo *montaarvore(const char *str, int *i)
{
    tNo *no = NULL;
    if (str[*i] == '(')
    {   
        (*i)++; 
        // Se o proximo nao eh um numero
        if (!(str[*i+1] >= 48 && str[*i+1] <= 57)) {
            no = inicia(&str[*i]);
            (*i)++;
        }
        else {
            int k = 0;
            char novoValor[50]; 
            for (int j = (*i);(str[j] >= 48 && str[j] <= 57);j++){
                k++;  
            } 
            strncpy(novoValor, &str[*i], k);
            (*i) += k;   
            no = inicia(novoValor); 
        }
        no->esq = montaarvore(str, i);
        no->dir = montaarvore(str, i);
        (*i)++;
    }
    return no;
}
/* -------------------------------------------------------------------------- */
int contaNos(tNo *no)
{
    if (no != NULL)
    {
        return contaNos(no->esq) + contaNos(no->dir) + 1;
    }
    else
        return 0;
}
/* -------------------------------------------------------------------------- */
void preordem(tNo *no)
{
    if (no != NULL)
    {
        printf("%d  ", no->valor);
        preordem(no->esq);
        preordem(no->dir);
    }
}
/* -------------------------------------------------------------------------- */
void emordem(tNo *no)
{
    if (no != NULL)
    {
        emordem(no->esq);
        printf("%d  ", no->valor);
        emordem(no->dir);
    }
}
/* -------------------------------------------------------------------------- */
void posordem(tNo *no)
{
    if (no != NULL)
    {
        posordem(no->esq);
        posordem(no->dir);
        printf("%d  ", no->valor);
    }
}
/* -------------------------------------------------------------------------- */
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