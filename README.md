# Arvore Binária analisadora de expressões aritméticas
Projeto 01- Disciplina CI1057   
Autor: Rubens Zandomenighi Laszlo - GRR20206147

# Compilação 
Para efetuar a compilação, basta digitar make all, para excluir todos os arquivos temporários digite make clean, 
e para excluir temporários e o executável digite make purge.
Ao compilar criará um arquivo executável com o nome teste.

# Execução
Para inserir novas strings para testes do programa basta inserir no arquivo expressoes.txt, deixando uma linha vazia na ultima linha. 
No seguinte formato: (*(5)(+(4)(3)))=35
Optei por passar o valor esperado da expressão para uma detecção mais fácil de possíveis erros. 
Como não existem tratativas de erros de envio da string de teste, esta deve ser enviada no formato de expressão com parênteses aninhados. 
Para executar o programa basta digitar ./teste
Para uma melhor visualização da execução do programa, optei por a cada operação efetuada pelo analisador, mostrar ao lado o resultado da operação. 
