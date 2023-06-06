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
	printf("  [1] Calcular Corrente \n  [2] Calcular Tens�o \n  [3] Calcular Resist�ncia \n\n  pressione qualquer tecla para sair\n\n");
	printf("  Escolha sua op��o para calcular: ");
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
			printf("  C�lculo da Corrente (informe os valores de V e R):\n\n");
			printf("  Tens�o (volts): ");
			scanf("%f", &tensao);
			printf("  Resist�ncia (ohms): ");
			scanf("%f", &resistencia);
			corrente = (tensao / resistencia);
			
			printf("\n O valor da corrente � igual a %.2f amperes", corrente);			
			break;
		
		case 2:
			Cabecalho();
			Clear();
			printf("  C�lculo da Tens�o (informe os valores de R e I):\n\n");
			printf("  Resistencia (ohms): ");
			scanf("%f", &resistencia);
			printf("  Corrente (ampere): ");
			scanf("%f", &corrente);
			tensao = (resistencia * corrente);
			
			printf("\n O valor da tens�o � igual a %.2f V", tensao);			
			break;
			
		case 3:
			Cabecalho();
			Clear();
			printf("  C�lculo da Resist�ncia (informe os valores de V e I):\n\n");
			printf("  Tens�o (volts): ");
			scanf("%f", &tensao);
			printf("  Corrente (ampere): ");
			scanf("%f", &corrente);
			resistencia = (tensao / corrente);
			
			printf("\n O valor da resistencia � igual a %.2f ohm", resistencia);		
			break;
			         
		default:
			break;
			
	}
		
}
