/*2) Elabore um programa com o uso de uma função recursiva para resolver a seguinte expressão:
f(n) = n * (1/n) * (1/n-1)..., observe n > 0.*/

#include <stdio.h>

float funcao(int num){
	int aux = num;
	
	if(num == 1)
		return 1;
		
	//Incompleto!	

	else if(aux > 0){
		aux--;
		return (1/num * funcao(num-1));
	}
}

int main(){
	int n; 
	float result;
	
	printf("Digite um numero: ");
	scanf("%d", &n);
	while(n <= 0){
		printf("Invalido! Digite um numero maior que zero: ");
		scanf("%d", &n);	
	}
	
	result = funcao(n);
	printf("n*(1/n)*(1/n-1)*... = %.2f", result);
}
