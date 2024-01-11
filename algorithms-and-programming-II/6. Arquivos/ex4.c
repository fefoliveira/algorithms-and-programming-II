/*4)	Faça um programa que leia um arquivo texto do disco, lendo linha a linha, e exibindo cada uma das linhas numeradas na tela. A ideia é podermos pegar um arquivo um arquivo texto qualquer (pode ser inclusive o arquivo do programa fonte - arquivo ".c" - de um destes exercícios) e mostrar na tela com as linhas numeradas. As primeiras linhas do arquivo iriam ser exibidas na tela da seguinte forma: 1: #include 2: #include 3: 4: FILE *ArqEntrada; 5: ... */

#include <stdio.h>
#include <stdlib.h>

int main(){
	char linha[300];
	FILE *arq;
	arq = fopen("1.c", "r");
	while(fgets(linha, 300, arq) != NULL){
		puts(linha);
	}
	fclose(arq);
}
