/*7) Crie uma função que recebe uma string e transforma alguns dos caracteres em maiúsculos e outros em minúsculos. 
Faça sorteios com a função rand() para gerar números aleatórios em C, que serão usados para escolher os índices dos 
caracteres que serão alterados.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h> //Para usar "rand()".
#include <ctype.h> //Para usar "toupper()" e "tolower()".

void funcao(char string[]){
	int minus, maius;
	//Inicializa a semente com o tempo atual do sistema.
    srand(time(NULL));
    
    //Gera um número aleatório no intervalo de 0 a strlen(string).
    minus = rand() % strlen(string);
	maius = rand() % strlen(string);
	
	if(minus != maius){
		string[minus] = tolower(string[minus]);
		string[maius] = toupper(string[maius]);
		//strlwr(string[minus]);
		///strupr(string[maius]);
		
		printf("Random: %d e %d \nA frase modificada ficou: ", minus, maius);
		puts(string);
	}
	else{
		printf("Os numeros randomizados foram iguais, portanto nao houveram modificacoes na frase.");
	}
}

int main(){
	int i, j;
	char str[30];
	
	printf("Digite uma frase: ");
	gets(str);
	
	funcao(str);
}
