/*3) Escreva um programa para calcular a m�dia aritm�tica dos entre o n�mero lido at� 1. 
Utilizando recursividade para o c�lculo. Exemplo se o n�mero lido for 6, o c�lculo ser� (6+5+4+3+2+1)/6.*/

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
