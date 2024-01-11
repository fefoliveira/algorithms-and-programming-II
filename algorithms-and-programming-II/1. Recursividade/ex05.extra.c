/*5.	Escreva uma função recursiva, SomaSerie(i,j,k: inteiro): inteiro, que devolva a somada 
série de valores do intervalo [i,j], com incremento k. (O exercício anterior só que retornando um número com tudo somado)*/

#include <stdio.h>

int SomaSerie(int i, int j, int k){
	if(i + k > j)
		return i;
	else
		return i + SomaSerie(i + k, j, k);
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
	printf("\nSoma = %d", SomaSerie(inicio, fim, incremento));
}
