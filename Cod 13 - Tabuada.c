#include <stdio.h>

#define KGRN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "KGRN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Tabuada "RESET"\n\n");
}

int main(){
	Cabecalho();	
	int numeroInteiro, x;	
	printf(" Informe qual numero deseja mostrar a tabuada: ");
	scanf("%d", &numeroInteiro);
	system("cls");
	Cabecalho();
	printf("\n Tabuada de %d\x1B[0m \n", numeroInteiro);
	x=1; while(x != 11){
		printf("\n %2.d x %d = %2.d", x, numeroInteiro, numeroInteiro*x); x++;
	} return 0;
}
