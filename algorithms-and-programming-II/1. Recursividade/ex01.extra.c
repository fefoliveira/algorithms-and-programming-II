/*1.	Escreva uma função recursiva, potencia(x,y), que devolva x elevado a potência y.*/

#include <stdio.h>

int pow(int x, int y);

int main(){
	int base, exp;
	
	printf("Digite a base da potencia: ");
	scanf("%d", &base);
	printf("Digite o expoente da potencia: ");
	scanf("%d", &exp);
	
	printf("\n%d^%d = %d", base, exp, pow(base, exp));
}

int pow(int x, int y){
	if(y == 0)
		return 1;
	else if(y == 1)
		return x;
	else if(x == 0)
		return 0;
	else{
		if(y > 1)
			return x * pow(x, y - 1);
	}
}
