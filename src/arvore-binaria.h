#include "estruturas.h"

tNo *inicia(char valor);
int checaSinal(char c);
tNo *montaarvore(const char *str, int *i);
int contaNos(tNo *no);
void preordem(tNo *no);
void emordem(tNo *no);
void posordem(tNo *no);
int altura(tNo *p);
