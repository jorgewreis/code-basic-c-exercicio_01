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
	printf("\n - Cod 29 > Jogo da memória numérico"RESET"\n\n");
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	// Declaração de variáveis
	int maximo, i, nivel, aleatorio1[5], aleatorio2[5], acertos=0;
   time_t tempo_atual;
	time(&tempo_atual);
	maximo = 99;	 
   srand((unsigned int)tempo_atual);
   
   do {
   	Cabecalho();
   	printf("\n Selecione o nível de dificuldade que deseja jogar: \n [1] Fácil \n [2] Médio \n [3] Difícil \n\n > ");
   	scanf("%d", &nivel);
   	Cabecalho();
   	printf("\n Serão sorteados 5 números. Preste atenção para inseri-los logo em seguida: \n\n");
   	system("pause");
   	for(i=0; i<5;i++){
	 		Cabecalho();
	 		if (nivel == 1){
	 			printf("\n Sorteando números - Nível fácil");
		   } else if (nivel == 2){
		   	printf("\n Sorteando números - Nível médio");
			} else {
				printf("\n Sorteando números - Nível difícil");
			}	 		
			printf("\n\n Preste atenção !!! \n\n");
	 		aleatorio1[i] = (rand()%maximo)+1;
	 		printf(" %d\n", aleatorio1[i]);
	 		sleep(4-nivel);
		 }
	} while (aleatorio1[4] == 0);
	
	Cabecalho();
	printf("\n Agora informe os números sorteados: \n");
	for (i=0;i<5;i++){		
		printf("\n %dº número sorteado > ", i+1);
		scanf("%d", &aleatorio2[i]);
	}
	Cabecalho();
	for (i=0;i<5;i++){
		if (aleatorio1[i] == aleatorio2[i]){
			acertos++;
		}
	}
	printf("\n Você acertou %d números", acertos);
	return 0;
}
