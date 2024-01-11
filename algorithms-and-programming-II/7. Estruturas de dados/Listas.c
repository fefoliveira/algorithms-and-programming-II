#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista{
	int dado2;
	struct lista *prox;
}knot;

void acima(knot **inicio2, int dados2);
void imprime(knot *inicio2);
void abaixo(knot **inicio2, int dado1f);
void remove_fim(knot **inicio2);

int main(){
	bool repete = true;
	int dado1, escolha;
	knot *inicio1 = NULL;

	while(repete){
		printf("1 - Inserir acima (a esquerda)"
		"\n2 - Inserir abaixo (a direita)"
		"\n3 - Imprimir"
		"\n4 - Remover ultimo item abaixo (a direita)"
		"\n5 - Sair"
		"\nSua escolha: ");
		scanf("%d", &escolha);
		while(escolha < 1 || escolha > 5){
			printf("Invalido! Digite sua escolha novamente: ");
			scanf("%d", &escolha);
		}
		switch(escolha){
			case 1:
				printf("\n----------------------------------\nDigite um valor: ");
				scanf("%d", &dado1);
				acima(&inicio1, dado1);
				printf("\tPonteiro:\t%d\n\tValor:\t\t%d \n\tProximo:\t%d\n----------------------------------\n\n", inicio1, inicio1->dado2, inicio1->prox);			
				break;
			case 2:
				printf("\n----------------------------------\nDigite um valor: ");
				scanf("%d", &dado1);
				abaixo(&inicio1, dado1);
				printf("\tPonteiro:\t%d\n\tValor:\t\t%d \n\tProximo:\t%d\n----------------------------------\n\n", inicio1, inicio1->dado2, inicio1->prox);		
				break;
			case 3:
				imprime(inicio1);
				break;		
			case 4:
				remove_fim(inicio1);
				break;
			case 5:
				repete = false;
				break;
		}
	}
}

void acima(knot **inicio2, int dado1f){
	knot *novo;
	novo = (knot*)malloc(sizeof(knot));
	if(novo == NULL)
		printf("\nMemoria insuficiente!");
	else{
		novo->dado2 = dado1f;
		if(inicio2 == NULL)
			novo->prox = NULL;
		else{
			novo->prox = *inicio2;
		}
		*inicio2 = novo;
	}	
}

void imprime(knot *inicio2){
	knot *aux;
	printf("\n----------------------------------\nLista -> ");
	aux = inicio2;
	printf("%d, ", aux->dado2);
	aux = aux->prox;
	while(aux != NULL){
		printf("%d, ", aux->dado2);
		aux = aux->prox;	
	}
	printf("fim.\n----------------------------------\n\n");
}

void abaixo(knot **inicio2, int dado1f){
	knot *novo, *aux;
	novo = (knot*)malloc(sizeof(knot));
	if(novo == NULL)
		printf("\nMemoria insuficiente!");
	else{
		novo->dado2 = dado1f;
		novo->prox = NULL;
		aux = *inicio2;
		if(aux == NULL)
			*inicio2 = novo;
		else{
			while(aux->prox != NULL){
			aux = aux->prox;
			}
		aux->prox = novo;
		}
	}
}

void remove_fim(knot **inicio2){
	knot *aux, *ant, *pos;
	aux = *inicio2;
	pos = NULL;
	if(aux->prox == NULL)
		printf("A lista esta vazia.");
	else{
		while(aux->prox != NULL){
			ant = aux;
			aux = aux->prox;
		}
		pos = aux;
		if(pos != NULL){
			ant->prox = pos->prox;
			free(pos);
			printf("\n----------------------------------\n\t"    "Removido\n----------------------------------\n\n");
		}
	}
}
			
void limpa(**inicio2){
	knot *inicio2aux;
	inicio2aux = *inicio2;
    if(inicio2 == NULL){
        free(inicio2);
    } 
    else{
        while(inicio2 != NULL){
            inicio2 = inicio2aux->prox;
            free(inicio2aux);
            inicio2aux = inicio2->prox;
        }
    }
}
