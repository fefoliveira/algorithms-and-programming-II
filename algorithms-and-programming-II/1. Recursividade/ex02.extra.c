/*2.	Escreva uma função recursiva, mdc(x,y), que receba dois valores inteiros e devolva o 
maior divisor comum aos dois valores recebidos. 

	Gerador de máximo divisor comum (mdc):
	- mdc(x, y) = y se x >= y e x mod y = 0	;			*(mod = resto da divisao (%))
	- mdc(x, y) = mdc(y, x), se x < y;
	- mdc(x, y) = mdc(y, x mod y), caso contrário.*/

#include <stdio.h>

int mdc(int x, int y);

int main(){
	int num1, num2;
	
	printf("Digite o primeiro valor: ");
	scanf("%d", &num1);
	printf("Digite o segundo valor: ");
	scanf("%d", &num2);
	
	printf("\nMDC(%d, %d) = %d", num1, num2, mdc(num1, num2));
}

int mdc(int x, int y){
	if(x >= y && x % y == 0) 	//Quando os dois próx. ifs derem x%y = 0, então essa vai ser a condição de parada e vai retorar o y.
		return y; 				//Aqui, quando cair no if(x < y), eu posso continuar deixando retornar y porque o y se refere ao segundo parâmetro, e não a variável usada no parâmetro.
	else if(x < y){
		return mdc(y, y%x);
	}
	else{
		return mdc(x, x%y);		//Vai fazer o x%y até que (x >= y && x % y == 0), diminuindo o valor do segundo parâmetro e o transformando no MDC.
	}
}
