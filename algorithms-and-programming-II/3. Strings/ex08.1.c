/*8) Crie uma função que duplique cada caractere da string.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

void funcao(char string[]){
	int i, j, k, tam;
	char temp1, temp2;
	tam = strlen(string)*2;
	
	for(i = 0; i < tam-2; i++){
		string[strlen(string)] = string[strlen(string)-1];
		for(j = strlen(string)-1; j > i+1; j--){
			string[j] = string[j-1];
		}
		if(i == 0)
			string[i+1] = string[i];
		if(i >= 1)
			i++;
	}
	printf("Frase modificada: ");
	puts(string);
}

int main(){
	char str[20];
	
	printf("Digite uma frase: ");
	gets(str);
	
	funcao(str);
}
