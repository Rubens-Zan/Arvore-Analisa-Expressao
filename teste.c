#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas.h"
#include "biblioteca.h"
#include "arvore-binaria.h"
#include "analisador.h"

void testaAnalisadorSenhas(){
    tNo *n;
    int i;
    int resultado;

    while(proximaExpressao()){

        i = 0;
        resultado = 0; 
        printf("\n"); 
        char *str = expressaoAtual();
        printf("Analisando expressao : '%s'\n", str); 
        
        n = montaarvore(str, &i); 
        analisaExpressao(n, &resultado); 
        if (testaResultado(resultado))
            printf("Sucesso!\n");
        else 
            printf("Erro ao calcular\n"); 
        
    }
}


int main(void)
{
    carregarExpressoes("expressoes.txt");
    testaAnalisadorSenhas();
    return 1;
};