#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int opcaoMenu;
float tensao, corrente, resistencia;

void Cabecalho(){
	system("cls");
	printf("\n Programa desenvolvido por Jorge Reis - Todos os direitos reservados. \n");
	printf(" Lei de Ohm - Grandezas fundamentais \n\n");
}

void MenuInicial(){
	printf("  [1] Calcular Corrente \n  [2] Calcular Tensão \n  [3] Calcular Resistência \n\n  pressione qualquer tecla para sair\n\n");
	printf("  Escolha sua opção para calcular: ");
	scanf("%d", &opcaoMenu);
}

void Clear(){
	resistencia = 0;
	tensao = 0;
	corrente = 0;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	Cabecalho();
	MenuInicial();
	
	switch(opcaoMenu){
		
		case 1:
			Cabecalho();
			Clear();
			printf("  Cálculo da Corrente (informe os valores de V e R):\n\n");
			printf("  Tensão (volts): ");
			scanf("%f", &tensao);
			printf("  Resistência (ohms): ");
			scanf("%f", &resistencia);
			corrente = (tensao / resistencia);
			
			printf("\n O valor da corrente é igual a %.2f amperes", corrente);			
			break;
		
		case 2:
			Cabecalho();
			Clear();
			printf("  Cálculo da Tensão (informe os valores de R e I):\n\n");
			printf("  Resistencia (ohms): ");
			scanf("%f", &resistencia);
			printf("  Corrente (ampere): ");
			scanf("%f", &corrente);
			tensao = (resistencia * corrente);
			
			printf("\n O valor da tensão é igual a %.2f V", tensao);			
			break;
			
		case 3:
			Cabecalho();
			Clear();
			printf("  Cálculo da Resistência (informe os valores de V e I):\n\n");
			printf("  Tensão (volts): ");
			scanf("%f", &tensao);
			printf("  Corrente (ampere): ");
			scanf("%f", &corrente);
			resistencia = (tensao / corrente);
			
			printf("\n O valor da resistencia é igual a %.2f ohm", resistencia);		
			break;
			         
		default:
			break;
			
	}
		
}
