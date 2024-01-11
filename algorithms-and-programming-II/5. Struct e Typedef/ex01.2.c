/*2) Crie uma estrutura representando os alunos de um determinado curso. 
A estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da segunda 
prova e nota da terceira prova. 
	(a) Permita ao usuário entrar com os dados de 5 alunos. 
	(b) Encontre o aluno com maior nota da primeira prova. 
	(c) Encontre o aluno com maior média geral. 
	(d) Encontre o aluno com menor média geral 
	(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para 
	aprovação.*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct{
	int matricula;
	char nome[30];
	float nota1, nota2, nota3, media;
}alunos;

int main(){
	int i, aluno_maior_nota1, media_maior = 0, media_menor;
	float maior_nota1 = 0;
	alunos aluno[5];
	for(i = 0; i < 5; i++){
		printf("Digite o numero de matricula do aluno %d: ", i+1);
		scanf("%d", &aluno[i].matricula);
		
		getchar();
		printf("Digite o nome do aluno %d: ", i+1);
		fgets(aluno[i].nome, sizeof(aluno->nome), stdin);	//gets que previne overflow
	
		printf("Digite a primeira nota do aluno %d: ", i+1);
		scanf("%f", &aluno[i].nota1);
		if(i = 0){
			maior_nota1 = aluno[i].nota1;
		}
		if(aluno[i].nota1 > maior_nota1){
			maior_nota1 = aluno[i].nota1;
			aluno_maior_nota1 = i+1;
		}
		
		printf("Digite a segunda nota do aluno %d: ", i+1);
		scanf("%f", &aluno[i].nota2);
		printf("Digite a terceira nota do aluno %d: ", i+1);
		scanf("%f", &aluno[i].nota3);
		printf("\n");
		
		aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3)/3; 
		if(i = 0){
			media_maior = aluno[i].media;
			media_menor = aluno[i].media;
		}
		if(aluno[i].media > media_maior)
			media_maior = aluno[i].media;
		else if(aluno[i].media < media_menor)
			media_menor = aluno[i].media;
		
	}
	printf("A maior nota da primeira prova foi do aluno %d.", aluno_maior_nota1);
	
}
