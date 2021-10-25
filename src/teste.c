/*
 * Autor: Rubens Zandomenighi Laszlo- GRR20206147
 * Data: 29/10/2021
 * Compila a partir do C, utilizando o comando make teste, para excluir arquivos executaveis e temporarios basta digitar make purge 
 * Programa que le as expressoes no arquivo de expressoes.txt e analisa as expressoes, retornando se o resultado
 * esperado esta equivalente ao resultado retornado. 
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
            printf("Erro ao calcular, resultado obtido: %d\n", resultado);
    }
}
int main(void)
{
    carregarExpressoes("expressoes.txt");
    testaAnalisadorSenhas();
    return 0;
};