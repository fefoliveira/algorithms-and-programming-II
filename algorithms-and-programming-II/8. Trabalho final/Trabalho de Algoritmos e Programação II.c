#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool validacao_cpf(char *cpf);					//Validação do CPF.
bool validacao_dia(int *nasc);					//Validação dos dias das datas.
bool arquivo_branco(FILE *file);				//Validação da existência de conteúdo em um arquivo já existente.
bool cpf_existente(FILE *arquivo, char *cpf);	//Validação da ocorrência de um CPF dentre os já cadastrados no arquivo.
void limpa_buffer();							//Função que limpa todo o lixo do buffer do teclado.
void lista_ultima_data();						//Função do case2.
void consulta_bairro();							//Função do case3.
void valor_acumulado();							//Função do case4.

typedef struct arquivo{
	char CPF[12], nome[60], bairro[30], rua[30], numero[10];
	int nascimento[3], ultima[3];
	float acumulado;
}clientela;

int main(){
	bool repete = true;
	int escolha;
	clientela cliente;
	FILE *arq;
	
	while(repete){
		arq = fopen("arquivo.txt", "r");
		//Se o arquivo não existir ou estiver em branco, só serão exibidas e permitidas duas opções no menu.
		if(arq == NULL || arquivo_branco(arq) == true){		
			printf("1 - Cadastrar cliente\n"
			"5 - Fim\n"
			"Sua escolha: ");
			scanf("%d", &escolha);
			limpa_buffer();
			while(escolha != 1 && escolha != 5){
				printf("Invalido! Digite novamente sua escolha: ");
				scanf("%d", &escolha);
				limpa_buffer();
			}	
		}
		//Caso exista um arquivo preenchido, todas as opções do menu serão exibidas e permitidas. 
		else{ 
			printf("1 - Cadastrar cliente\n"
			"2 - Listar cliente que fez compra em uma data informada (Informar CPF, nome, e endereÃ§o (bairro, rua e numero)\n"
			"3 - Contar quantos clientes moram em um bairro informado pelo teclado\n"
			"4 - Listar o nome do cliente que tem o maior valor acumulado de compras\n"
			"5 - Fim\n"
			"Sua escolha: ");
			scanf("%d", &escolha);
			while(escolha < 1 || escolha > 5){
				printf("Invalido! Digite novamente sua escolha: ");
				scanf("%d", &escolha);
			}	
		}
		fclose(arq);	//Fecho o arquivo depois de cada utilização 
		
		switch(escolha){
			case 1:
				//----------------------------------------------------------
				printf("\n\nDigite o CPF do cliente: ");
				scanf("%12s", &cliente.CPF);
				limpa_buffer();
				
				arq = fopen("arquivo.txt", "r");
				if(arq != NULL){	//Impede o cadastro de um CPF inválido (ou de já cadastrado, caso exista um arquivo).
					while(validacao_cpf(cliente.CPF) == false || cpf_existente(arq, cliente.CPF) == true){
						printf("Invalido! Digite novamente o CPF do cliente: ");
						scanf("%12s", &cliente.CPF);
						limpa_buffer();
						//Abre e fecha (evita alguns erros):
						fclose(arq);
						arq = fopen("arquivo.txt", "r");
					}
					fclose(arq);
				}
				else{	//Impede o cadastro de um CPF inválido
					while(validacao_cpf(cliente.CPF) == false){
						printf("Invalido! Digite novamente o CPF do cliente: ");
						scanf("%12s", &cliente.CPF);
						limpa_buffer();
					}
				}
				//----------------------------------------------------------
				
				
				//----------------------------------------------------------
				printf("Digite o nome do cliente: ");
				fgets(cliente.nome, sizeof(cliente.nome), stdin);
				//Para essa e outras partes do cadastro que recebem uma string como dado, só é válido o input caso seu primeiro caractere seja alfanumérico.
				while(!isalnum(cliente.nome[0])){	
					printf("Invalido! Digite novamente o nome do cliente: ");
					fgets(cliente.nome, sizeof(cliente.nome), stdin);
				}
				//----------------------------------------------------------
				

				//----------------------------------------------------------
				printf("Digite o endereco do cliente:");
				
				printf("\n\tBairro: ");
				fgets(cliente.bairro, sizeof(cliente.bairro), stdin);
				while(!isalnum(cliente.bairro[0])){
					printf("\tInvalido! Digite novamente o bairro: ");
					fgets(cliente.bairro, sizeof(cliente.bairro), stdin);	
				}
				strupr(cliente.bairro);		//O nome do bairro é gravado em maísculas para a facilitação da comparação no case3.
				
				printf("\tRua: ");
				fgets(cliente.rua, sizeof(cliente.rua), stdin);
				while(!isalnum(cliente.rua[0])){
					printf("\tInvalido! Digite novamente a rua: ");
					fgets(cliente.rua, sizeof(cliente.rua), stdin);
				}
				strupr(cliente.rua);		//O nome da rua tambem é gravado em maísculas, porém só pela organização estética dos caracteres no arquivo.
				
				printf("\tNumero (0 para S/N): ");
				fgets(cliente.numero, sizeof(cliente.numero), stdin);
				while(!isalnum(cliente.numero[0])){
					printf("\tInvalido! Digite novamente o numero (0 para S/N): ");
					fgets(cliente.numero, sizeof(cliente.numero), stdin);
				}
				//----------------------------------------------------------
				
				
				//----------------------------------------------------------
				printf("Digite a data de nascimento do cliente:");	//Dados das duas datas requisitadas são recebidos e gravados no arquivo como inteiros.
				
				printf("\n\tAno: ");
				scanf("%d", &cliente.nascimento[2]);
				while(cliente.nascimento[2] < 1900 || cliente.nascimento[2] > 9999){
					printf("\tInvalido! Digite o ano novamente: ");
					scanf("%d", &cliente.nascimento[2]);
				}
				
				printf("\tMes: ");
				scanf("%d", &cliente.nascimento[1]);
				while(cliente.nascimento[1] < 1 || cliente.nascimento[1] > 12){
					printf("\tInvalido! Digite o mes novamente: ");
					scanf("%d", &cliente.nascimento[1]);
				}
				
				printf("\tDia: ");
				scanf("%d", &cliente.nascimento[0]);
				while(validacao_dia(cliente.nascimento) == false){
					printf("\tInvalido! Digite o dia novamente: ");
					scanf("%d", &cliente.nascimento[0]);
				}
				//----------------------------------------------------------
				
				
				//----------------------------------------------------------
				printf("Digite a data da ultima compra feita pelo cliente:");
				
				printf("\n\tAno: ");
				scanf("%d", &cliente.ultima[2]);
				while(cliente.ultima[2] < cliente.nascimento[2] || cliente.ultima[2] > 9999){
					printf("\tInvalido! Digite o ano novamente: ");
					scanf("%d", &cliente.ultima[2]);
				}
				
				printf("\tMes: ");
				scanf("%d", &cliente.ultima[1]);
				while(cliente.ultima[1] < 1 || cliente.ultima[1] > 12 || (cliente.ultima[2] == cliente.nascimento[2] && cliente.ultima[1] < cliente.nascimento[1])){
					printf("\tInvalido! Digite o mes novamente: ");
					scanf("%d", &cliente.ultima[1]);
				}
				printf("\tDia: ");
				scanf("%d", &cliente.ultima[0]);
				while(validacao_dia(cliente.ultima) == false || (cliente.ultima[2] == cliente.nascimento[2] && cliente.ultima[1] == cliente.nascimento[1] && cliente.ultima[0] < cliente.nascimento[0])){
					printf("\tInvalido! Digite o dia novamente: ");
					scanf("%d", &cliente.ultima[0]);
				}
				//----------------------------------------------------------
				
				
				//----------------------------------------------------------
				printf("Digite o valor acumulado das compras feitas por este cliente: ");	//Valor da última compra é recebido e gravado no arquivo como float (.2f).
				scanf("%f", &cliente.acumulado);
				while(cliente.acumulado < 0){
					printf("Invalido! Digite novamente o valor acumulado das compras feitas por este cliente: ");
					scanf("%f", &cliente.acumulado);	
				}
				printf("\n");
				//----------------------------------------------------------
				
				//----------------------------------------------------------
				//Gravação de todos os dados do struct no arquivo:
				cliente.nome[strlen(cliente.nome)-1] = '\0';
				cliente.bairro[strlen(cliente.bairro)-1] = '\0';
				cliente.rua[strlen(cliente.rua)-1] = '\0';
				cliente.numero[strlen(cliente.numero)-1] = '\0';
				
				arq = fopen("arquivo.txt", "a+");
				fprintf(arq, "%s;", cliente.CPF);
				fprintf(arq, "%s;", cliente.nome);
				fprintf(arq, "%s;", cliente.bairro);
				fprintf(arq, "%s;", cliente.rua);
				fprintf(arq, "%s;", cliente.numero);
				//------------------------
				if(cliente.nascimento[0] < 10)
					fprintf(arq, "0%d/", cliente.nascimento[0]);
				else
					fprintf(arq, "%d/", cliente.nascimento[0]);
				if(cliente.nascimento[1] < 10)
					fprintf(arq, "0%d/", cliente.nascimento[1]);
				else
					fprintf(arq, "%d/", cliente.nascimento[1]);
				fprintf(arq, "%d;", cliente.nascimento[2]);
				//------------------------
				if(cliente.ultima[0] < 10)
					fprintf(arq, "0%d/", cliente.ultima[0]);
				else
					fprintf(arq, "%d/", cliente.ultima[0]);
				if(cliente.ultima[1] < 10)
					fprintf(arq, "0%d/", cliente.ultima[1]);
				else
					fprintf(arq, "%d/", cliente.ultima[1]);
				fprintf(arq, "%d;", cliente.ultima[2]);
				//------------------------
				fprintf(arq, "%.2f\n", cliente.acumulado);
				fclose(arq);
				//----------------------------------------------------------
				printf("\n");
				break;
			case 2:
				lista_ultima_data();
				break;
			case 3:
				consulta_bairro();
				break;
			case 4:
				valor_acumulado();
				break;
			case 5:
				repete = false;
				break;
		}
	}
}
bool validacao_cpf(char *cpf){
	int i, j, cont, d1 = 0, d1_resto, d2 = 0, d2_resto;
	
	//Verifica se o CPF tem 11 digitos:
	if(strlen(cpf) != 11)
		return false;
	
	//Verifica se o CPF tem todos os digitos iguais:
	for(i = 0, j = 1; j < 11; i++, j++){
		if(cpf[i] == cpf[j]){
			cont++;
		}
	}
	if(cont >= 10)
		return false;
		
	//CÃ¡lculo do primeiro digito verificador:
	for(i = 8, j = 2; i >= 0; i--, j++){
		d1 += (cpf[i]-'0') * j;
	}
	d1_resto = d1%11;
	if(d1_resto < 2)
		d1 = 0;
	else
		d1 = 11-d1_resto;
	if((cpf[9]-'0') != d1)
		return false; 

	//CÃ¡lculo do segundo digito verificador:
	for(i = 9, j = 2; i > 0; i--, j++){
		d2 += (cpf[i]-'0') * j;
	}
	d2_resto = d2%11;
	if(d2_resto < 2)
		d2 = 0;
	else
		d2 = 11-d2_resto;
	if((cpf[10]-'0') != d2)
		return false;

	return true;
}

bool validacao_dia(int *nasc){
	//Verifica o intervalo de dias padrÃ£o:
	if(nasc[0] < 1 || nasc[0] > 31)
		return false;
	
	//Verifica se o ano Ã© bissexto e se 29/02 Ã© possÃ­vel:
	if(nasc[1] == 2 && nasc[0] == 29){
		if((nasc[2] % 4 == 0 && nasc[2] % 100 != 0) || nasc[2] % 400 == 0){
			return true;
		}
		else
			return false;
	}
	
	//Impede 30/02 ou 31/02:
	if(nasc[1] == 2 && (nasc[0] == 30 || nasc[0] == 31))
		return false;
	
	//Impede o dia 31 em meses que nÃ£o o possuem:
	if((nasc[1] == 4 || nasc[1] == 6 || nasc[1] == 9 || nasc[1] == 11) && nasc[0] == 31)
		return false;
		
	return true;
}

bool arquivo_branco(FILE *file){
	int aux;
    while ((aux = fgetc(file)) != EOF) {
        if (aux != ' ' && aux != '\t' && aux != '\n' && aux != '\r') {
        	//Percorre todo o arquivo, se for encontrado algo além de espaços em branco, então retorna false;
            return false;
        }
    }
    return true;
}

bool cpf_existente(FILE *arquivo, char *cpf){
	char linha[12];
	while(fgets(linha, 12, arquivo) != NULL){
		//Percorre os 12 primeiro caracteres de cada linha do arquivo, e retorna true caso acha algum igual ao que está tentando ser cadastrado.
		if(strcmp(linha, cpf) == 0){
			return true;
		}
	}
	return false;
}

void limpa_buffer(){
	int aux;
	//Limpa todo o lixo do buffer (usando getchar()) enquanto o resultado não foi o fim da linha ou o fim do arquivo.
	while(aux != '\n' && aux != EOF){
		aux = getchar();
	}
}

void lista_ultima_data(){
	bool iguais = false;
	int data[3], cont, i, j, k, tam;
	char data2[10], linha[300], aux[11], *p[5];
	FILE *arq;
	
	//----------------------------------------------------------
	//Recebimento da data de consulta:
	printf("\n\nDigite a data que deseja consultar: ");
	
	printf("\n\tAno: ");
	scanf("%d", &data[2]);	
	while(data[2] < 1900 || data[2] > 9999){
		printf("\tInvalido! Digite o ano novamente: ");
		scanf("%d", &data[2]);
	}
	
	printf("\tMes: ");
	scanf("%d", &data[1]);
	while(data[1] < 1 || data[1] > 12){
		printf("\tInvalido! Digite o mes novamente: ");
		scanf("%d", &data[1]);
	}
	
	printf("\tDia: ");
	scanf("%d", &data[0]);
	while(validacao_dia(data) == false){
		printf("\tInvalido! Digite o dia novamente: ");
		scanf("%d", &data[0]);
	}
	//----------------------------------------------------------
	
	
	//----------------------------------------------------------
	//Transformação da data digitada para uma string:
	if(data[0] < 10){
		data2[0] = '0';
		data2[1] = data[0] + 48;
	}
	else
		snprintf(data2, 2, "%d", data[0]);
	data2[2] = '/';	
	
	if(data[1] < 10){
		data2[3] = '0';
		data2[4] = data[1] + 48;
	}
	else{
		snprintf(data2 + strlen(data2), 2, "%d", data[1]);
	}
	data2[5] = '/';
	data2[6] = '\0';	//Limpa o ano antes de alguma alteraÃ§Ã£o.
	snprintf(data2 + strlen(data2), 4, "%d", data[2]);
	data2[10] = '\0';
	//----------------------------------------------------------
	
	
	//----------------------------------------------------------
	printf("Resultados:");
	arq = fopen("arquivo.txt", "r");
	if(arq == NULL)
	    printf("Ocorreu algum erro ao tentar abrir o arquivo.\n");
	else{
		while(fgets(linha, 300, arq)){
			i = 0;
			j = 0;
			k = 0;
			cont = 0;
			tam = strlen(linha);
			for(j = 0; j <= tam; j++){
				if(linha[j] == ';'){
					cont++;
				}
				if(cont == 6){
					aux[k] = linha[j+1];
					k++;
				}
			}		
			aux[k-1] = '\0';
			cont = 0;
			if(strcmp(data2, aux) == 0){		//Imprime os resultados caso ache algum cliente com data equivalente.
				iguais = true;
				p[0] = strtok(linha, ";");		//Divisão da string em tokens.
				for(k = 1; k < 5; k++){
					p[k] = strtok(NULL, ";");
				}
				printf("\n\t----------------");
				printf("\n\tCPF: %s", p[0]);
				printf("\n\tNome: %s", p[1]);
				printf("\n\tBairro: %s", p[2]);
				printf("\n\tRua: %s", p[3]);
				printf("\n\tNumero: %s", p[4]);
			}
		}
	}
	if(iguais == false){
		printf(" Nao foram encontrados clientes com datas de ultima compra equivalentes a da consulta.\n");
	}
	else
		printf("\n\t----------------");
	//----------------------------------------------------------
	fclose(arq);
	printf("\n\n");
}

void consulta_bairro(){
	int cont, i, j, k, tam, qtd;
	char linha[300], bairro[30], aux2[30];
	FILE *arq;
	
	//----------------------------------------------------------
	getchar();
	printf("\n\nDigite o bairro que deseja consultar: ");
	fgets(bairro, sizeof(bairro), stdin);
	while(!isalnum(bairro[0])){
		printf("\tInvalido! Digite novamente o bairro que deseja consultar: ");
		fgets(bairro, sizeof(bairro), stdin);
	}
	bairro[strlen(bairro)-1] = '\0';
	strupr(bairro);
	//----------------------------------------------------------
	
	
	//----------------------------------------------------------
	arq = fopen("arquivo.txt", "r");
	if(arq == NULL)
	    printf("Ocorreu algum erro ao tentar abrir o arquivo.\n");
	else{
		//Mesmo esquema da função anterior, porém dessa vez incrementando um contador cada vez que o bairro inserido é achado em alguma linha.
		qtd = 0;
		while(fgets(linha, 300, arq) != NULL){
			i = 0;
			j = 0;
			k = 0;
			cont = 0;
			tam = strlen(linha);
			for(j = 0; j <= tam; j++){
				if(linha[j] == ';'){
					cont++;
				}
				if(cont == 2){
					aux2[k] = linha[j+1];
					k++;
				}
			}
			aux2[k-1] = '\0';
			cont = 0;
			if(strcmp(bairro, aux2) == 0){
				qtd++;
			}
		}
	}
	if(qtd > 1)
		printf("Foram encontrados %d clientes que moram no bairro consultado.\n\n\n", qtd);
	else if(qtd == 1)
		printf("Foi encontrado 1 cliente que mora no bairro consultado.\n\n\n");
	else
		printf("Nao foi encontrado nenhum cliente morador do bairro consultado.\n\n\n");
	//----------------------------------------------------------
	fclose(arq);
}

void valor_acumulado(){
	int cont, i, j, k, cont2;
	char linha[300], *p[7], bairro[30], aux2[50], maior_nome[50];
	double maior, aux3;
	FILE *arq;
	
	arq = fopen("arquivo.txt", "r");
	if(arq == NULL)
	    printf("Ocorreu algum erro ao tentar abrir o arquivo.\n");
	else{
		i = 0;
		maior = 0;
		aux3 = 0;
		while(fgets(linha, 300, arq) != NULL){
			j = 0;
			k = 0;
			cont = 0;
			p[0] = strtok(linha, ";");
			for(k = 1; k < 8; k++){
				p[k] = strtok(NULL, ";");
			}
			//Manipulação do maior valor (e do nome o qual comprou).
			if(i == 0){	
				maior = atof(p[7]);		//Transforma a string em float.
				aux3 = atof(p[7]);
				strcpy(maior_nome, p[1]);
				maior_nome[strlen(maior_nome) + 1] = '\0';
			}
			else{
				aux3 = atof(p[7]);
				if(aux3 > maior){
					maior = aux3;
					strcpy(maior_nome, p[1]);
					maior_nome[strlen(maior_nome) + 1] = '\0';
				}
			}
			i++;
		}
	}
	printf("\n\nO cliente que tem o maior valor acumulado de compras foi: ", maior_nome);
	puts(maior_nome);
	printf("Valor de compras acumulado por este cliente: %.2f\n\n", maior);
	fclose(arq);
}
