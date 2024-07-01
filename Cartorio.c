#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string

int registro(){
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salvo o valor da vari�vel
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
			printf("CPF N�O ENCONTRADO!");
		}
		
		while(fgets(conteudo, 200, file) != NULL){
			printf("\nEssas s�o as informa��es do usu�rio: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		system("pause");
}

int deletar(){
	printf("Voc� escolheu DELETAR NOME\n");
	system("pause");
}

int main(){
	
	int opcao = 0; //Definindo vari�veis
	int laco = 1;
	
	for(laco = 1; laco = 1; ){
		
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio do Davi ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar os nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Op��o: "); //Fim do menu

		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //Limpa o terminal ap�s digitar algo
		
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
				printf("OP��O INV�LIDA!\n");
				system("pause");
			break;
				
		}
	}
}
