/*3) Escreva um programa para calcular a média aritmética dos entre o número lido até 1. 
Utilizando recursividade para o cálculo. Exemplo se o número lido for 6, o cálculo será (6+5+4+3+2+1)/6.*/

#include <stdio.h>

float funcao(float n, float n2){
	if(n == 0 || n == 1)
		return n/n2;
	else{
		n += funcao(n-1, n2);
	}
	//return n/n2;
}

int main(){
	float num = 6;
	num = funcao(num, num);
	printf("%.2f", num);
}
