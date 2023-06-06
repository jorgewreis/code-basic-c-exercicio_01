#include <stdio.h>

#define KGRN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "KGRN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Numeros pares menores que o informado "RESET"\n\n");
}

int main(){
	Cabecalho();	
	int numeroInteiro, x, numeroResultado;	
	printf(" Informe qual numero deseja mostrar os pares menores que ele: ");
	scanf("%d", &numeroInteiro);
	while(numeroInteiro == 0){
		system("cls");
		Cabecalho();
		printf(" Informe qual numero deseja mostrar os pares menores que ele (diferente de zero): ");
		scanf("%d", &numeroInteiro);
	}
	system("cls");
	Cabecalho();
	printf(" Lista dos numeros pares inteiros menores que %d", numeroInteiro);
	x = numeroInteiro;
	while(x != 0){
		numeroResultado = x % 2;
		if (numeroResultado == 0){
			printf("\n  %d", x);
		}
		if (x>0){
			x--;
		} else {
			x++;
		}		
	}
		
	return 0;
}
