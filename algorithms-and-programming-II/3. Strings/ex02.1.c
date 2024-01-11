/*2) Crie uma função que transforma todos os caracteres de uma string em minúsculos.
(manualmente, sem usar strupr()!)*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

void funcao(char string[]){
	int i;
	for(i = 0; i < strlen(string); i++){
		if(string[i] >= 65 && string[i] <= 90)
			string[i] += 32; //Trabalhando com ASCII
	}	
}

int main(){
	int i;
	char str[20];
		
	printf("Digite uma frase: ");
	gets(str);
	funcao(str);
	printf("Frase com todos seus catacteres em minusculos: ");
	puts(str);
}
