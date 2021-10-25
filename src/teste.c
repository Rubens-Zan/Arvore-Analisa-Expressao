/*
 * Autor: Rubens Zandomenighi Laszlo- GRR20206147
 * Data: 29/10/2021
 * Compila a partir do C, utilizando o comando make teste, para limpar basta digitar make clean 
 * Programa que le as expressoes no arquivo de expressoes de teste e analisa as expressoes, retornando seu resultado
 * e se estao corretos. 
*/
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
        printf("Analisando expressao : \n'%s'\n", str); 
        n = montaarvore(str, &i); 
        analisaExpressao(n, &resultado); 
        if (testaResultado(resultado)){
            printf("Resultado: %d\n", resultado);
        }
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