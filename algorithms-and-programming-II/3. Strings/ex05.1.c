/*5) Crie uma função que mostra os caracteres de uma string são repetidos.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

int funcao(char str[], char repetidos[]){
	int i, j, k = 0;
	
	int m, temp;
	
	for(i = 0; i < strlen(str); i++){
		for(j = i+1; j < strlen(str); j++){
			if(str[j] == str[i]){
				//Teste pra ver se a letra repetida já não foi adicionada na string de repetidos.
				for(m = 0; m < k; m++){
					if(repetidos[m] == str[i]){
						temp = 1;
						m = k;
					}
				}
				//Adição da letra repetida na string de repetidos.
				if(temp == 0){ 
					repetidos[k] = str[i];
					k++;
					j = strlen(str);
				}
				//Reset de temp.
				else
					temp = 0;
					
			}
		}
	}
	return k;
}

int main(){
	int i, k;
	char string[20], repeat[10];
	
	printf("Digite uma frase: ");
	gets(string);
	while(strlen(string) <= 1){
		printf("Invalido! Digite uma frase com 2 ou mais caracteres: ");
		gets(string);		
	}
	
	k = funcao(string, repeat);
	
	
	printf("Caracteres repetidos na frase: ");
	for(i = 0; i < k; i++){
		printf("%c / ", repeat[i]);
	}
}
