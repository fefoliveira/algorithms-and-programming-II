/*3)�Crie uma fun��o que recebe uma string e um caractere, e retorne o n�mero de vezes que esse 
caractere aparece na string.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
	int i, cont = 0;
	char str[10], car[1];
	
	printf("Digite uma frase: ");
	gets(str);
	printf("Digite um caractere: ");
	scanf("%c", &car[0]);
	
	for(i = 0; i < strlen(str); i++){
		if(str[i] == car[0])
			cont++;
	}
	
	printf("O caracter '%c' apareceu %d vez(es) na frase.", car[0], cont);
}
