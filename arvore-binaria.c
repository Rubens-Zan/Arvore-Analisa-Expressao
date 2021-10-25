/* Includes */
#include "estruturas.h"
#include "arvore-binaria.h"
#include <stdio.h>
#include <string.h>

/* Funções */
/*Função para inicialização do nó, com alocação de memória e atribuição de valores 
  para os componentes do nó.*/
int checaSinal(char c){
    return (c == '+' || c == '-' || c == '/' || c == '*' );
};
/* -------------------------------------------------------------------------- */
tNo *inicia(char valor)
{
    tNo *n = (tNo *)malloc(sizeof(tNo));
    if (checaSinal(valor)){
        if (valor == '+'){
            n->valor = MAIS;
        }
        else if(valor == '-'){
            n->valor = MENOS;
        }
        else if(valor == '/'){
            n->valor = DIVISAO;
        }
        else if(valor == '*'){
            n->valor = VEZES;
        } 
    }
    else {
        n->valor = valor - '0';
    }
    n->dir = NULL;
    n->esq = NULL;
    return n;
}
/* -------------------------------------------------------------------------- */
tNo *iniciaMaior(const char *str)
{ 
    tNo *n = (tNo *)malloc(sizeof(tNo));
    n->valor = atoi(str);    
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
            char novoValor[50]; 
            for (int j = (*i);(str[j] >= 48 && str[j] <= 57);j++){
                k++;  
            } 
            strncpy(novoValor, &str[*i], k);
            (*i) +=k;   
            no = iniciaMaior(novoValor); 
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