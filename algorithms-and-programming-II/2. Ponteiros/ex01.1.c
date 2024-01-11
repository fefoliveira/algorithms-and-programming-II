/*1)	Escreva um programa que utilizando uma função minmax que receba um vetor inteiro e os
endereços de duas variáveis inteiras (min e max), e deposite nessas variáveis o valor do 
mínimo valor do vetor e o valor de um elemento máximo do vetor, respectivamente.
No main o vetor é lido via teclado e depois imprime os valores de min e max.
O vetor armazena até 10 valores inteiros.*/

#include <stdio.h>

void minmax(int vetor[10], int tam, int* p_min, int* p_max){
	int i;
	*p_max = vetor[0];
	*p_min = vetor[0];
	for(i = 0; i < tam; i++){
		if(vetor[i] > *p_max)
			*p_max = vetor[i];
		else if(vetor[i] < *p_min)
			*p_min = vetor[i];
	}
}

int main(){
	int vetor[10], i, n, min, max, cont = 0;
	
	for(i = 0, n = 1; i < 10 && n == 1; i++){
		cont++;
		printf("Digite um valor para o vetor (%d/10): ", i+1);
		scanf("%d", &vetor[i]);
		if(i != 9){
			printf("-> Deseja digitar mais um valor? [1 - Sim] [0 - Nao]: ");
			scanf("%d", &n);
			while(n != 1 && n != 0){
				printf("-> Invalido! Deseja digitar mais um valor? [1 - Sim] [0 - Nao]: ");
				scanf("%d", &n);	
			}
			if(n == 0)
				n = 0;
		}
	}
	
	minmax(vetor, cont, &min, &max);
	printf("\nMin: %d \nMax: %d", min, max);
}
