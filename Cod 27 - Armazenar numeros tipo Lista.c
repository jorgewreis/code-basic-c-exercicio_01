#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"


int qtdNum, opMenu;
int numero[10];
char opCadastro;

void Cabecalho(){
	system("cls");
	printf("\n "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Armazenamento de numeros tipo FILA"RESET"\n\n");
}

void MostraMenu(){
	printf(" Menu: \n\n");
	printf(" [1] Cadastrar \n [2] Listar valores cadastrados \n [3] Remover número \n [4] Sair \n\n > ");
	scanf("%d", &opMenu);
}

void CadastraNumero(){
	do {
		Cabecalho();
		printf("\n Digite um número para ser armazenado no banco de dados: ");
		scanf("%d", &numero[qtdNum]);
		printf("\n\n Número %d armazenado na posição %d \n", numero[qtdNum], qtdNum);
		qtdNum++;
		printf("\n\n Deseja cadastrar outro número? [s] Sim ou [n] Não \n > ");
		scanf(" %c", &opCadastro);
		opCadastro = tolower(opCadastro);
		if (opCadastro == 'n'){
			break;
		}		
	} while(qtdNum < 10);
}

void ImprimirLista(){
	int i;
	for(i = 0; i < sizeof(numero)/sizeof(numero[0]); i++){
		if (numero[i] > 0){
			printf("\n %d. %d", i, numero[i]);
		}		
	}
}

void DeletarNumero(){
	int i;
	for (i = 0;i < 9;i++){
		numero[i] = numero[i+1];
	}
	numero[9] = 0;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	do {
		Cabecalho();
		MostraMenu();
		switch(opMenu)
		{
			case 1:
				Cabecalho();
				CadastraNumero();
				printf("\n\n");
				break;
			case 2:
				Cabecalho();
				ImprimirLista();
				printf("\n\n");
				system("pause");
				break;
			case 3:
				Cabecalho();
				DeletarNumero();
				printf("\n\n");
				system("pause");
				break;
			case 4:
				break;
				
			default:
				while (opMenu != 1 && 2 && 3 && 4){
					Cabecalho();
					printf(" \n Valor inválido de opção \n > ");
					scanf("%d", &opMenu);
				}			
		}
	} while (opMenu < 4);	
	
}
