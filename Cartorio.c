#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar da string

int registro(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta(){
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o CPF a ser consultado: ");
		scanf("%s", cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL){
			printf("CPF NÃO ENCONTRADO!");
		}
		
		while(fgets(conteudo, 200, file) != NULL){
			printf("\nEssas são as informações do usuário: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		system("pause");
}

int deletar(){
	printf("Você escolheu DELETAR NOME\n");
	system("pause");
}

int main(){
	
	int opcao = 0; //Definindo variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1; ){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório do Davi ###\n\n"); //Início do menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //Limpa o terminal após digitar algo
		
		switch(opcao){
			case 1: 
				registro();
			break;
			
			case 2:
				consulta();
			break;
			
			case 3:
				deletar();
			break;
			
			default:
				printf("OPÇÃO INVÁLIDA!\n");
				system("pause");
			break;
				
		}
	}
}
