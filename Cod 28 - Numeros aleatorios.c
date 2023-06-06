#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Cod 29 > Jogo da mem�ria num�rico"RESET"\n\n");
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	// Declara��o de vari�veis
	int maximo, i, nivel, aleatorio1[5], aleatorio2[5], acertos=0;
   time_t tempo_atual;
	time(&tempo_atual);
	maximo = 99;	 
   srand((unsigned int)tempo_atual);
   
   do {
   	Cabecalho();
   	printf("\n Selecione o n�vel de dificuldade que deseja jogar: \n [1] F�cil \n [2] M�dio \n [3] Dif�cil \n\n > ");
   	scanf("%d", &nivel);
   	Cabecalho();
   	printf("\n Ser�o sorteados 5 n�meros. Preste aten��o para inseri-los logo em seguida: \n\n");
   	system("pause");
   	for(i=0; i<5;i++){
	 		Cabecalho();
	 		if (nivel == 1){
	 			printf("\n Sorteando n�meros - N�vel f�cil");
		   } else if (nivel == 2){
		   	printf("\n Sorteando n�meros - N�vel m�dio");
			} else {
				printf("\n Sorteando n�meros - N�vel dif�cil");
			}	 		
			printf("\n\n Preste aten��o !!! \n\n");
	 		aleatorio1[i] = (rand()%maximo)+1;
	 		printf(" %d\n", aleatorio1[i]);
	 		sleep(4-nivel);
		 }
	} while (aleatorio1[4] == 0);
	
	Cabecalho();
	printf("\n Agora informe os n�meros sorteados: \n");
	for (i=0;i<5;i++){		
		printf("\n %d� n�mero sorteado > ", i+1);
		scanf("%d", &aleatorio2[i]);
	}
	Cabecalho();
	for (i=0;i<5;i++){
		if (aleatorio1[i] == aleatorio2[i]){
			acertos++;
		}
	}
	printf("\n Voc� acertou %d n�meros", acertos);
	return 0;
}
