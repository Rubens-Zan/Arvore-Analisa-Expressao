# Arvore Binária analisadora de expressões aritméticas
Projeto 01- Disciplina CI1057   
Autor: Rubens Zandomenighi Laszlo - GRR20206147

## Compilação 
Compila a partir do C, utilizando comandos make.  
Para efetuar a compilação, basta digitar make all,  
Para excluir todos os arquivos temporários digite make clean,   
e para excluir temporários e o executável digite make purge.  
Ao compilar criará um arquivo executável com o nome teste.

## Execução
O programa le as expressõoes de entrada do arquivo expressoes.txt, armazenando as expressões e os resultados esperados. 
Para cada expressão é criada uma árvore binária sendo que os números serão nós folhas, e as operações (*, /, -, +) serão os nós internos.
Posteriormente, sendo analisadas e retornando o resultado calculado. 

Para inserir novas expressões para testes do programa basta inserir a expressão no arquivo expressoes.txt, com o resultado esperado, 
sendo que a última linha do arquivo deve ser uma linha em branco.  
No seguinte formato:   
(*(5)(+(4)(3)))=35  
Optei por passar o valor esperado da expressão para uma detecção mais fácil de possíveis erros. 
Como não existem tratativas de erros de envio da string de teste, esta deve ser enviada no formato de expressão com parênteses aninhados,
sem erros.  
Para executar o programa basta digitar ./teste

## Saída
Para uma melhor visualização da execução do programa, optei por a cada operação efetuada pelo analisador, mostrar ao lado o resultado da operação. 
Por exemplo, na expressão acima:  
_(*(5)(+(4)(3)))=35_  
4 + 3 = 7  
5 * 7 = 35  
Resultado: 35  

