/*3.	Escreva uma função recursiva que faça o seguinte: leia um número; se o número for
negativo, a função para; caso contrário, a função imprime o número e faz uma chamada 
recursiva a si mesma.*/

#include <stdio.h>

void funcao(){
	int num;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	if(num < 0)
		printf("Numero negativo.");
	else{
		printf("Numero digitado: %d\n\n", num);
		return funcao();
	}
}

int main(){
	funcao();
}
