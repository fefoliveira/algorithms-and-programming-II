/*4) Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses caracteres na string.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>

void remover(char str_mod[], char carac, int tamanho){
	/*Sempre que eu for passar um vetor/string por parametro pra uma função, eu o escrevo como, por ex.: "int str[]", 
	além de não precisar usar asteriscos DENTRO da função quanto quero manipular as posições desse vetor.*/
	int i, j;
	for(i = 0; i < tamanho; i++){
		if(str_mod[i] == carac){		
			for(j = i; j < tamanho; j++){
				str_mod[j] = str_mod[j+1];	
			}
			tamanho = strlen(str_mod);
			i--;
		}
	}
}

int main(){
	int i, j, cont = 0, tam;
	char str[10], car;
	
	printf("Digite uma frase: ");
	gets(str);
	tam = strlen(str);
	
	printf("Digite um caractere: ");
	scanf("%c", &car);
	
	remover(str, car, tam); //Passa o ponteiro como parâmetro da função.
	printf("Frase modificada: ");
	puts(str);
}
