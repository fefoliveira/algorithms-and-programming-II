/*3)	Fa�a 2 programas, um que leia o arquivo TEXTO criado no exerc�cio 1 e outro que leia o arquivo BIN�RIO criado no exerc�cio 2. Exibir na tela os dados lidos dos respectivos arquivos. */

#include <stdio.h>
#include <stdlib.h>

int main(){
//	char linha[300];
//	FILE *arq;
//	arq = fopen("dados.txt", "r");
//	if (arquivo == NULL)	
//        printf("Erro ao abrir o arquivo.\n");
//	while(fgets(linha, 300, arq) != NULL){
//		printf("%s", linha);
//	}
//	fclose(arq);
	
	//N�o funciona, tenho que arrumar:
	int numero;
	FILE *arq;
	arq = fopen("dados.bin", "rb");
	if(arq == NULL)	
        printf("Erro ao abrir o arquivo.\n");
	    while(fread(&numero, sizeof(int), 1, arq) == 1){
			printf("%d\n", numero);
	}
	fclose(arq);

}
