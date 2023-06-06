#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"


int qtdNum;
int numero[10];
char opCadastro;

void Cabecalho(){
	system("cls");
	printf("\n "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Armazenamento de numeros "RESET"\n\n");
}

void imprimirLista(){
	int i;
	for(i = 0; i < sizeof(numero)/sizeof(numero[0]); i++){
		printf("\n %d. %d", i, numero[i]);
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
		
	do {
		Cabecalho();
		printf("\n Digite um número para ser armazenado no banco de dados: ");
		scanf("%d", &numero[qtdNum]);
		printf("\n\n Número %d armazenado na posição %d \n", numero[qtdNum], qtdNum);
		printf("\n\n Deseja cadastrar outro número? [s] Sim ou [n] Não \n > ");
		scanf(" %c", &opCadastro);
		opCadastro = tolower(opCadastro);
		if (opCadastro == 'n'){
			break;
		} else {
			qtdNum++;
		}
		
	} while(qtdNum < 10);
	
	imprimirLista();
	
}
