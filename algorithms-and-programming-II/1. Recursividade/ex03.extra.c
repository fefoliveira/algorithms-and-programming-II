/*3.	Escreva uma fun��o recursiva que fa�a o seguinte: leia um n�mero; se o n�mero for
negativo, a fun��o para; caso contr�rio, a fun��o imprime o n�mero e faz uma chamada 
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
