#include <stdio.h>

#define KGRN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "KGRN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Fatorial "RESET"\n\n");
}

int main(){
	Cabecalho();	
	int numeroInteiro, x, numeroResultado;	
	printf(" Informe qual numero deseja mostrar seu fatorial: ");
	scanf("%d", &numeroInteiro);
	while(numeroInteiro<1){	   	
		system("cls");
		Cabecalho();
		printf(" Informe qual numero deseja mostrar seu fatorial (maior que zero): ");
		scanf("%d", &numeroInteiro);
	}
	system("cls");
	Cabecalho();
	x = numeroInteiro;
	while(x > 0){
		numeroResultado = numeroResultado*x;
	   x--;
	} 
	printf("\n Fatorial de %d! = %d", numeroInteiro, numeroResultado);
	return 0;
}
