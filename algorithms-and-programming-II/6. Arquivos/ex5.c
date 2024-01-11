/*5)	Fa�a um programa que imite um editor de textos. Inicialmente voc� ir� ler os dados digitados pelo usu�rio (linhas de texto) e criar um vetor em mem�ria onde ser�o armazenados os textos fornecidos pelo usu�rio (texto de 1 at� no m�ximo 50 linhas). O usu�rio vai escrever o seu texto, terminando por uma linha onde ele ir� escrever apenas a palavra 'FIM', o que determina que ele n�o deseja mais digitar linhas de texto. Sendo assim, o texto final pode ter um n�mero vari�vel de linhas, entre 1 e 50. Salvar o conte�do armazenado na mem�ria neste vetor, em um arquivo texto em disco. Sugest�o: use o comando "gets" ou "fgets" para ler as linhas de texto digitadas pelo usu�rio. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int main(){
	char string[300], aux[300], fim[3] = "FIM";
	bool repete = true;
	FILE *arq;
	arq = fopen("texto.txt", "w");
	printf("Digite seu texto (texto com no max. 50 linhas, usando enter para cada pulo de linha e 'Fim' para finalizar):\n\n");
	while(repete){
		printf("\t");
		fgets(string, 300, stdin);
		strcpy(string, aux);
		strupr(aux);
		if(strcmp(aux, fim) == 0)
			repete = false;
		fprintf(arq, "%s\n;", string);
	}
	fclose(arq);
	printf("Texto salvo no arquivo texto.txt.\n");
}
