# Makefile compilacao programa analisador de expressoes aritmeticas

CFLAGS = -Wall -g 

MODULOS = biblioteca \
	analisador \
	arvore-binaria

OBJETOS = teste.o $(addsuffix .o,$(MODULOS)) 

.PHONY : all clean

all : teste

teste : $(OBJETOS)

clean : 
	$(RM) $(OBJETOS)

purge: 
	$(RM) $(OBJETOS) teste
