#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"

#define MAX_RESULTADOS 100
static char expressoes[MAX_RESULTADOS][50];     /* matriz com expressões testadas   */
static char resultados[MAX_RESULTADOS][50];     /* matriz com resultados das expressões testadas   */
static unsigned int nResultados = 0;            /* quantidade de resultados do arquivo */
static unsigned int resultadoAtual = -1;        /* qual o resultado atual */

/* -------------------------------------------------------------------------- */
unsigned int proximaExpressao(void) {
  resultadoAtual++;
  return(resultadoAtual < nResultados);
//   if (resultadoAtual < nResultados)
//       return 1;
//   return 0;
}
/* -------------------------------------------------------------------------- */
void carregarExpressoes(char *nomeArquivo){
    char * line = NULL;
    size_t len = 0;
    size_t read;
    FILE *fp = fopen(nomeArquivo, "r");
    printf("--Lendo expressoes de teste--\n");
    if (fp == NULL){
         printf("Nao foi possivel ler o arquivo\n");
         exit(EXIT_FAILURE);
    }
    nResultados = 0;
    while ((read = getline(&line, &len, fp)) != -1  && (nResultados < MAX_RESULTADOS)) {
        tratarExpressoes(line); 
        nResultados++;
    }
    printf("leitura das expressões completa, %d expressões lidas\n",nResultados);
    fclose(fp);
}
/* -------------------------------------------------------------------------- */
void tratarExpressoes(char *line){
    if (strcmp(&line[strlen(line)-1], " "))
        line[strlen(line)-1] = '\0';
    else
        line[strlen(line)] = '\0';
    char delim[] = "=";
    strcpy(expressoes[nResultados], strtok(line, delim)); 
    strcpy(resultados[nResultados], strtok(NULL, delim));  
}
/* -------------------------------------------------------------------------- */
unsigned int testaResultado(int resultado){  
    return (resultado == atoi(resultados[resultadoAtual]));
}
/* -------------------------------------------------------------------------- */
char *expressaoAtual(void){
    return expressoes[resultadoAtual];
}