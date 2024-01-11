/*2.	Escreva uma fun��o recursiva, mdc(x,y), que receba dois valores inteiros e devolva o 
maior divisor comum aos dois valores recebidos. 

	Gerador de m�ximo divisor comum (mdc):
	- mdc(x, y) = y se x >= y e x mod y = 0	;			*(mod = resto da divisao (%))
	- mdc(x, y) = mdc(y, x), se x < y;
	- mdc(x, y) = mdc(y, x mod y), caso contr�rio.*/

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
	if(x >= y && x % y == 0) 	//Quando os dois pr�x. ifs derem x%y = 0, ent�o essa vai ser a condi��o de parada e vai retorar o y.
		return y; 				//Aqui, quando cair no if(x < y), eu posso continuar deixando retornar y porque o y se refere ao segundo par�metro, e n�o a vari�vel usada no par�metro.
	else if(x < y){
		return mdc(y, y%x);
	}
	else{
		return mdc(x, x%y);		//Vai fazer o x%y at� que (x >= y && x % y == 0), diminuindo o valor do segundo par�metro e o transformando no MDC.
	}
}
