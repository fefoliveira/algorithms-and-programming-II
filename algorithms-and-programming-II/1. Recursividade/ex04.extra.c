/*4.	Escreva uma função recursiva, ImprimeSerie(i,j,k: inteiro), que imprime na tela a
série de valores do intervalo [i,j] (somente o "miolo", não precisa imprimir o i e o j), 
com incremento k. */

#include <stdio.h>

void ImprimeSerie(int i, int j, int k){
	if(i + k < j){
		printf("%d  ", i + k);
		ImprimeSerie(i, j, i + k);
	}
}

int main(){
	int inicio, fim, incremento;
	printf("Digite o inicio do intervalo: ");
	scanf("%d", &inicio);
	printf("Digite o fim do intervalo: ");
	scanf("%d", &fim);
	while(fim < inicio){
		printf("O numero final do intervalo precisa ser maior que o incial. Digite novamente o fim do intervalo: ");
		scanf("%d", &fim);
	}
	printf("Digite o incremento da contagem: ");
	scanf("%d", &incremento);
	printf("\n");
	ImprimeSerie(inicio, fim, incremento);
}
