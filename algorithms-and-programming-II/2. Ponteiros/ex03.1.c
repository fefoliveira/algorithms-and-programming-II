/*3)	Escreva um programa que contenha duas vari�veis inteiras. Compare seus endere�os e exiba a vari�vel que 
encontra-se no maior endere�o.*/

#include <stdio.h>

int main(){
	int *v1, *v2, a = 0, b = 0;
	
	v1 = &a; 	//"v1" recebe o a posi��o de mem�ria de "a" (vai alterar o valor de a, por ele so recebe posi��es de mem�ria).
	v2 = &b; 	
	
	printf("Digite um valor inteiro: ");
	//Se usa "%x" pra ponteiros
	scanf("%x", &*v1); 	//A posi��o de mem�ria que "v1" aponta vai receber o valor escaneado (vai colocar dentro do "a").
	printf("Digite outro valor inteiro: ");
	scanf("%d", &v2);
	
	if(a == b)
		printf("Os enderevos s�o iguais.");
	else if(a > b)
		printf("O endereco do valor %d e maior.", v2);
	else
		printf("O endereco do valor %d e maior.", v2);
}
