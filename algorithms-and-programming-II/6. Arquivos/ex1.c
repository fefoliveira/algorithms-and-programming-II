/*1)	Fa�a um programa que crie um arquivo TEXTO em disco, com o nome "dados.txt", e escreva neste arquivo em disco uma contagem que v� de 1 at� 100, com um n�mero em cada linha. Abra este arquivo em um editor de textos, como por exemplo o Notepad.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i; 
	FILE *arq = fopen("dados.txt", "w");
	if(arq == NULL)
		printf("Erro ao tentar abrir o arquivo.");
	else{
		for(i = 0; i < 101; i++){
	        fprintf(arq, "%d\n", i);
	    }
	    fclose(arq);
	    printf("Sucesso na gravacao dos dados.");
	}
}
