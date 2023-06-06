#include <stdio.h>
#include <math.h>
#include <locale.h>

int opcaoMenu;
float x, y, resultado;

void Cabecalho(){
	system("cls");
	printf("\n Programa desenvolvido por Jorge Reis - Todos os direitos reservados. \n");
	printf(" Biblioteca Math.h \n\n");
}

void MenuInicial(){
	printf("  [1] Potência \n  [2] Raiz \n  [3] Arredondar valor \n\n  pressione qualquer tecla para sair\n\n");
	printf("  Escolha sua opção para calcular: ");
	scanf("%d", &opcaoMenu);
}

void Clear(){
	x = 0;
	y = 0;
	resultado = 0;
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	opcaoMenu = 1;
	while (opcaoMenu != 0){
	
		Cabecalho();
		MenuInicial();
		
		switch(opcaoMenu){
			
			case 1:
				Cabecalho();
				Clear();
				printf("  Cálculo de potência \n\n");
				printf("  Informe um valor: ");
				scanf("%f", &x);
				printf("  Informe o valor do expoente: ");
				scanf("%f", &y);
				resultado = pow(x, y);
				printf("  > %.f^%.f = %.f", x, y, resultado);
				printf("\n\n");
				system("pause");
				opcaoMenu = 1;
				break;
			
			case 2:
				Cabecalho();
				Clear();
				printf("  Cálculo de raiz \n\n");
				printf("  Informe um valor: ");
				scanf("%f", &x);
				printf("  Informe o valor do índice: ");
				scanf("%f", &y);
				resultado = pow(x,1/y);
				printf("  > Raiz %.f de %.f = %.2f", y, x, resultado);
				printf("\n\n");
				system("pause");
				opcaoMenu = 1;
				break;
				
			case 3:
				Cabecalho();
				Clear();
				printf("  Arredondar valor para baixo \n\n");
				printf("  Informe um valor: ");
				scanf("%f", &x);
				resultado = ceil(x)									;
				printf("  > O valor arredondado de %.4f é %.f", x, resultado);
				printf("\n\n");
				system("pause");
				opcaoMenu = 1;
				break;
				      			   
			default:
				Clear();
				opcaoMenu = 0;
				break;
		}
	}
		
}
