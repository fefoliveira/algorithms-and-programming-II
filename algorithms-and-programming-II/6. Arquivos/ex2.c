/*Faça um programa que crie um arquivo BINÁRIO em disco, com o nome "dados.bin", e escreva neste arquivo em disco uma contagem que vá de 1 até 100, com um número em cada linha. Abra este arquivo em um editor de textos e observe como ficou o seu conteúdo.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i; 
	FILE *arq = fopen("dados.bin", "w");
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
