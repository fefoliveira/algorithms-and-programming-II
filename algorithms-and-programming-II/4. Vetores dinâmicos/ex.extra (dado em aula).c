/*Elabore um programa que armazena as notas de 2 provas e 1 trabalho de um número não fixo de alunos de uma turma 
(a nota 1 tem peso 2, a 2 tem peso 3 e a 3 peso 1), posteriormente calcule a média das três notas para cada aluno da 
turma. Depois imprima um relatório que compara a média de cada aluno com a média da turma informando ao lado do índice 
do aluno e sua média se ele está abaixo, acima ou na média da turma.*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	float *p1, *p2, *trab, *media_aluno, media_turma;
	int i, j, num;
	
	printf("Digite a quantia de alunos da turma: ");
	scanf("%d", &num);
	while(num <= 0){
		printf("Invalido! Digite novamente a quantia de alunos da turma: ");
		scanf("%d", &num);	
	}
	printf("\n");
	
	//Mallocs:
	p1 = (float*)malloc(num*(sizeof(float)));
	p2 = (float*)malloc(num*(sizeof(float)));
	trab = (float*)malloc(num*(sizeof(float)));
	media_aluno = (float*)malloc(num*(sizeof(float)));
	
	if(p1 != NULL && p2 != NULL && trab != NULL && media_aluno != NULL){
		for(i = 0; i < num; i++){
			for(j = 0; j < 3; j++){
				switch(j){
					case 0:
						printf("Digite a nota da PROVA 1  do aluno %d:  ", i);
						scanf("%f", &p1[i]);
						break; 
					case 1:
						printf("Digite a nota da PROVA 2  do aluno %d:  ", i);
						scanf("%f", &p2[i]);
						break; 
					case 2:
						printf("Digite a nota do TRABALHO do aluno %d:  ", i);
						scanf("%f", &trab[i]);
						break;
				}
			}
			media_aluno[i] = (p1[i]*2.0 + p2[i]*3.0 + trab[i])/6.0;
		}
		
		//Média da turma:
		for(i = 0; i < num; i++){
			media_turma += media_aluno[i];
		}
	
		//Impressão:		
		for(i = 0; i < num; i++){
			printf("\nMEDIA DO ALUNO %d: %.2f", i, media_aluno[i]);
		}
		printf("\n\nMEDIA GERAL DA TURMA = %.2f", media_turma/(float)num);
	}
	else{
		printf("\n\t\tESTOURO DE MEMORIA!");
	}
}
