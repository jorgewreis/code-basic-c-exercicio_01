#include <stdio.h>
#include <locale.h>

#define COR_VERDE "\x1B[32m"
#define RESET "\033[0m"

// variaveis globais
int option;
float totalCompra;
float desconto;
float totalPagar;

void Cabecalho(){
	system("cls");
	printf("\n "COR_VERDE"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Calvin Klein Store"RESET"\n\n");
}

void Menu(){
	printf(" [1] Comprar produtos\n");
	printf(" [2] Caixa\n\n");
	printf(" [0] Sair\n\n");
	printf(" Informe sua opção para abrir: ");	
}

void Compras(){
	int optionCompra;
	float valorProduto;
		
	do{
		system("cls");
		Cabecalho();
		printf(" COMPRA DE PRODUTOS\n\n");
		printf(" Informe o valor do produto: R$ ");
		scanf("%f", &valorProduto);
		totalCompra = totalCompra + valorProduto;
		printf("\n\n Deseja comprar outro produto? [1] Sim - [2] Não >> ");
		scanf("%d", &optionCompra);
	} while (optionCompra == 1);
	option = 1;
}

void Caixa(){
	system("cls");
	Cabecalho();
	printf(" COMPRA DE PRODUTOS\n\n");
	printf(" Valor da compra: R$ %.2f \n", totalCompra);
	
	if (totalCompra > 1000){
		desconto = totalCompra*0.15;
	} else if (totalCompra > 500.01){
		desconto = totalCompra*0.1;
	} else if (totalCompra > 300){
		desconto = totalCompra*0.05;
	}
	
	printf(" Desconto:        R$ %.2f \n", desconto);
	
	totalPagar = totalCompra-desconto;
	
	printf(" \n\n Valor a pagar: R$ %.2f\n\n", totalPagar);
	system("pause");	
}

int main(){		
	setlocale(LC_ALL, "portuguese");
		
	do{
		Cabecalho();
		Menu();		
		scanf("%d", &option);
		switch(option){
			case 1:
				Compras();			
				break;
			
			case 2:
				Caixa();
				break;
				
			default:
                break;
		}		
	} while (option != 0);
	return 0;
}
