/*2)	Faça um programa que leia 2 valores inteiros e chame uma função que receba estas  2 variáveis e troque o seu 
conteúdo, ou seja, esta função é chamada passando duas variáveis e, após  a execução da função¸ os valores das duas 
variáveis devem ter sido trocados entre si. Utilize ponteiros para a implementação do programa.*/

#include <stdio.h>

void funcao(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int *v1, *v2, a, b;
	
	v1 = &a; 	//"v1" recebe o a posição de memória de "a" (vai alterar o valor de a, por ele so recebe posições de memória).
	v2 = &b;
	
	printf("Digite um valor inteiro: ");
	//Se usa "%x" pra ponteiros
	scanf("%x", &*v1); 	//A posição de memória que "v1" aponta vai receber o valor escaneado (vai colocar dentro do "a").
	printf("Digite outro valor inteiro: ");
	scanf("%x", &*v2);
	
	printf("\nValor 1: %d \nValor 2: %d", *v1, *v2);
	funcao(v1, v2);
	printf("\n\nValor 1: %d \nValor 2: %d", a, b); //Tanto faz se por "*v1" ou "a", os dois significam a mesma coisa (o conteúdo que tem dentro de a).
}

