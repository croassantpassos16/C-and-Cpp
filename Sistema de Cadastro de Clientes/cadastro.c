#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>

bool continuar = true;
bool manter = true;

//Criação da classe Clientes
typedef struct
{
    char nome[20], email[30], endereco[50];
    int idade, telefone, cpf, rg;
} Cliente;

Cliente cliente[20];
int totalClientes = 0;

//Funções de apoio estético
void pulaLinha(int qnt) {
     int i;
    for (i = 0; i < qnt; i++) {
        printf("\n");
    }
}

void cabecalho(){
	system("cls");
    printf("\n\n\n================================================CADASTRO DE CLIENTES====================================================");
    pulaLinha(3);	
}

//Funções do sistema
void sobreSis(){
	cabecalho();
    printf("----------------------------------------------------SOBRE O SISTEMA-----------------------------------------------------");
    pulaLinha(5);
    printf("\n\t\tEste sistema foi criado como material de portfólio profissional, nele, destaca-se o");
	printf("\n\t\t\tconhecimento de tópicos importantes, como funções, cálculos,"); 
	printf("\n\tvetores e muitos outros, para a demonstração de conhecimento na linguagem de programação em C e C++\n\n\n\n");
}


void cadastro(Cliente *cliente, int *totalClientes){

    int continuar10, menu;
    
	cabecalho();
    printf("-------------------------------------------------CADASTRAR CLEINTES-----------------------------------------------------");
    pulaLinha(5);
    
	if(*totalClientes >= 20){
        printf("\n\n\t\t\tLimite de clientes exercido");
        return;
    }

    Cliente *novo = &cliente[*totalClientes];
    getchar();

    printf("\n\tDigite o nome do cliente: "); scanf("%[^\n]", novo->nome);
    printf("\n\tDigite a idade do cliente %s: ", novo->nome); scanf("%d", &novo->idade);
    printf("\n\tDigite o CPF do cliente %s: ", novo->nome); scanf("%d", &novo->cpf);
    printf("\n\tDigite o RG do cliente %s: ", novo->nome); scanf("%d", &novo->rg);
    printf("\n\tDigite o email do cliente %s: ", novo->nome); getchar(); scanf("%[^\n]", novo->email);
    printf("\n\tDigite o telefone do cliente %s para contato: ", novo->nome); scanf("%d", &novo->telefone);
    printf("\n\tDigite o endereço do cliente %s: ", novo->endereco); getchar(); scanf("%[^\n]", novo->endereco);

    system("cls");

    printf("\n\n\t\t\tExibicao dos dados do cliente %s:\n\n", novo->nome);
    printf("\n\n\t\tNome do cliente: %s\n\t\tIdade do cliente: %d\n\t\tCPF do cliente: %d\n\t\tRG do cliente: %d\n\t\tEmail do cliente: %s\n\t\tTelefone do cliente: %d\n\t\tEndereço do cliente: %s\n",
    novo->nome, novo->idade, novo->cpf, novo->rg, novo->email, novo->telefone, novo->endereco);

    (*totalClientes)++;

    printf("\n\nCliente cadastrado com sucesso\n\n");
    printf("Deseja cadastrar outro cliente? Digite 1 para sim e 0 para não: ");
    scanf("%d", &continuar10);

    if(continuar10 == 1){
        continuar = true;
    }else{
        continuar = false;
        printf("Deseja ir para o menu principal ou sair do sistema? Digite 1 para menu principal e 0 para sistema: "); scanf("%d", &menu);

        if(menu == 1){
            manter = true;
        }else{
            manter = false;
        }
    }
}

void verClientes(Cliente *cliente, int *totalClientes){

    int i;

    cabecalho();
	printf("------------------------------------------------CLIENTES CADASTRADOS----------------------------------------------------");
	pulaLinha(5);
    
	if(*totalClientes == 0){
        printf("\t\t\tNão há clientes cadastrados!\n\n\n\n");
        system("pause");
        return;
    }

    for(i = 0; i < *totalClientes; i++){

        Cliente *novo = &cliente[i];

        printf("\t\t\tExibicao dos dados do cliente %s:\n\n", novo->nome);
        printf("\n\n\t\tNome do cliente: %s\n\t\tIdade do cliente: %d\n\t\tCPF do cliente: %d\n\t\tRG do cliente: %d\n\t\tEmail do cliente: %s\n\t\tTelefone do cliente: %d\n\t\tEndereço do cliente: %s\n\n\n",
        novo->nome, novo->idade, novo->cpf, novo->rg, novo->email, novo->telefone, novo->endereco);
    }
    
	pulaLinha(4);
	system("pause");
}

//Rotina principal
int main(){

    int op, apoio;

    setlocale(LC_ALL, "");
	system("color 7D");

    while(manter){
 
 		cabecalho();
    	printf("Opções Disponíveis:");
    	pulaLinha(1);
    	sleep(1);
    	printf("\n\t\t1 - Sobre o sistema\n");
    	sleep(1);
		printf("\t\t2 - Cadastrar novo cliente\n");
    	sleep(1);
		printf("\t\t3 - Ver clientes cadastrados\n");
    	sleep(1);
		printf("\t\t4 - Sair");
		sleep(1);
    	pulaLinha(2);
    	printf("Digite a opções desejada: "); scanf("%d", &op);
    	continuar = true;
  
    	switch(op){
        	case 1:
        	sobreSis();
        	system("pause");
        	break;

        	case 2:
        	while(continuar){
            	cadastro(cliente, &totalClientes);
            	}
        	break;

        	case 3:
        	verClientes(cliente, &totalClientes);
        	break;

        	case 4:
        	printf("\nSaindo do sistema em 3...");
        	sleep(1);
    		printf("\nSaindo do sistema em 2...");
        	sleep(1);
        	printf("\nSaindo do sistema em 1...");
    	    sleep(1);
			manter = false;
        	break;

        	default:
        	printf("Não existe a opção solicitada!");
        	break;
    	}
    }
    return 0;
}
