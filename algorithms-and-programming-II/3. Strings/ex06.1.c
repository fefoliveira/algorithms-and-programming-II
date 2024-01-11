/*6) Crie uma função que retira todas os caracteres repetidos de uma string.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

int main(){
	int i, j, k, l, check = 0;
	char str[10], car, *repetidos;
	
	printf("Digite uma frase: ");
	gets(str);
	while(strlen(str) <= 1){
		printf("Invalido! Digite uma frase com 2 ou mais caracteres: ");
		gets(str);		
	}
	
	for(i = 0; i < strlen(str);){
		for(j = i+1; j < strlen(str); j++){
			if(str[j] == str[i]){
				check = 1;
				car = str[i];
				
				for(k = i; k < strlen(str);){
					if(str[k] == car){
						for(l = k; l < strlen(str); l++){
							str[l] = str[l+1];
						}
					}
					else
						k++;
				}
			}
		}
		if(check == 0)
			i++;
		else
			check = 0;
	}
	
	printf("Frase sem os caracteres repetidos: ");
	puts(str);
}
