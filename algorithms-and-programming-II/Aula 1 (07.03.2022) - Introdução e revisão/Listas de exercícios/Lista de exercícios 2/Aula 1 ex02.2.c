#include <stdio.h>

int main(){
	int vet_a[6], vet_b[10], i, cont, j, vet_ax[6], vet_bx[10], continua = 1;
	 
	for(i = 0; i < 6; i++){
		printf("Digite o %do numero do gabarito da Mega-Sena: ", i+1);
		scanf("%d", &vet_a[i]);
		while(continua){
			if(vet_a[i] > 0 && vet_a[i] <= 60){
				if(i > 0){
					for(j = i; j >= 0; j--){
						if(vet_a[j] == vet_a[j-1])
						
					}
				}
			}
			else{
				printf("Invalido! Digite novamente o %do numero do gabarito da Mega-Sena: ", i+1);
				scanf("%d", &vet_a[i]);
			}
		}
	}
	
	printf("\n");
	for(i = 0; i < 10; i++){
		printf("Digite o %do numero da aposta: ", i+1);
		scanf("%d", &vet_b[i]);
		while(vet_b[i] <= 0 || vet_b[i] > 60){
			printf("Invalido! Digite novamente o %do numero da aposta: ", i+1);
			scanf("%d", &vet_b[i]);
		}
	}
	cont = 0;
	for(i = 0; i < 6; i++){
		for(j = 0; j < 10; j++){
			if(vet_a[i] == vet_b[j])
				cont++;
		}	
	}
	if(cont == 6)
		printf("\nParabens! Voce obteve uma SENA!");
	else if(cont == 5)
		printf("\nParabens! Voce obteve uma QUINA!");
	else if(cont == 4)
		printf("\nParabens! Voce obteve uma QUADRA!");
	else
		printf("\nInfelizmente nao foi dessa vez...");
}
