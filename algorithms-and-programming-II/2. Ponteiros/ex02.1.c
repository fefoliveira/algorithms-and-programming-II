/*2)	Fa�a um programa que leia 2 valores inteiros e chame uma fun��o que receba estas  2 vari�veis e troque o seu 
conte�do, ou seja, esta fun��o � chamada passando duas vari�veis e, ap�s  a execu��o da fun��o� os valores das duas 
vari�veis devem ter sido trocados entre si. Utilize ponteiros para a implementa��o do programa.*/

#include <stdio.h>

void funcao(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main(){
	int *v1, *v2, a, b;
	
	v1 = &a; 	//"v1" recebe o a posi��o de mem�ria de "a" (vai alterar o valor de a, por ele so recebe posi��es de mem�ria).
	v2 = &b;
	
	printf("Digite um valor inteiro: ");
	//Se usa "%x" pra ponteiros
	scanf("%x", &*v1); 	//A posi��o de mem�ria que "v1" aponta vai receber o valor escaneado (vai colocar dentro do "a").
	printf("Digite outro valor inteiro: ");
	scanf("%x", &*v2);
	
	printf("\nValor 1: %d \nValor 2: %d", *v1, *v2);
	funcao(v1, v2);
	printf("\n\nValor 1: %d \nValor 2: %d", a, b); //Tanto faz se por "*v1" ou "a", os dois significam a mesma coisa (o conte�do que tem dentro de a).
}

