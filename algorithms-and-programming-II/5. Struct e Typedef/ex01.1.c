/*1) Crie um programa que permita armazenar o nome, a altura e da data de nascimento de até
10 pessoas.
Cada pessoa deve ser representada por uma struct dentro de um vetor. 
O nome, a data de nascimento e a altura de cada pessoa devem ser informados pelo teclado.
Posteriormente imprima os nomes das pessoas que possuem altura superior a 1,78.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct people{
	char nome[30];
	float altura;
	int data[3];
}pessoa;

int main(){
	int i;
	pessoa p[10];
	for(i = 0; i < 3; i++){
		printf("Para a %da pessoa:\n", i+1);
		printf("\tDigite seu nome: ", i+1);
		gets(p[i].nome);
		printf("\tDigite sua altura: ");
		scanf("%f", &p[i].altura);
		printf("\tDigite o dia do seu nascimento: ");
		scanf("%d", &p[0].data);
		printf("\tDigite o mes do seu nascimento: ");
		scanf("%d", &p[1].data);
		printf("\tDigite o ano do seu nascimento: ");
		scanf("%d", &p[3].data);
		printf("\n");
	}
	
	for(i = 0; i < 3; i++){
		printf("Pessoa %d:"
		"\n\tNome: "
		"\n\tAltura: "
		"\n\tData de nascimento: ", i+1, p[i].nome, p[i].altura, p[i].data);
	
	}
	
}
