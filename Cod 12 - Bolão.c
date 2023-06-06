#include <stdio.h>
#include <locale.h>
#include <time.h>

void delay(int seconds){
	clock_t start_time=clock();
	while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

void Cabecalho(){
	int x;
	printf("\n Aguarde, carregando");
	for (x=0;x<5;x++){
		 delay(1);
		 printf(".");
	}
	system("cls");
	printf("\n\x1b[1m\x1B[32m Programa desenvolvido por Jorge Reis - Todos os direitos reservados.\x1B[0m \n");
	printf(" Bolão do Senai - 08/05 20:00 - Santos x Bahia \n\n");
}

void MenuInicial(){
	printf("  [1] Informar quantidade de participantes \n  [2] Cadastrar palpites \n  [3] Informar resultado \n\n  \x1b[1m\x1B[31m[0] Sair\x1B[0m\n\n");
	printf("  Escolha sua opção para continuar: ");
}

int main(){
	setlocale(LC_ALL, "portuguese");

	int opcaoMenu, qtdPessoas, x;
	char jogador[10][20];
	int palpite[10][3];
	int resultado[2];
	
	opcaoMenu = 1;
	qtdPessoas = 1;
	while (opcaoMenu != 0){
	
		Cabecalho();
		MenuInicial();	
		scanf("%d", &opcaoMenu);
	
		switch(opcaoMenu){
			
			case 0:
				opcaoMenu = 0;
				break;
				
			case 1:
				system("cls");
				Cabecalho();
				printf("  Informe a quantidade de participantes: ");
				scanf("%d", &qtdPessoas);
				if (qtdPessoas > 10){
					qtdPessoas = 10;
				}
				system("cls");
				break;
				
			case 2:
				system("cls");
				Cabecalho();
				printf("  Cadastre os palpites: ");
				x = 1;
			   while (x <= qtdPessoas){
					printf("\n  Nome do jogador %d: ", x);
					scanf("%s[^n]", &jogador[x]);
					printf("\n  %s informe seu palpite: \n   Santos: ", jogador[x]);
					scanf("%d", &palpite[x][1]);
					printf("   Bahia: ");
					scanf("%d", &palpite[x][2]);
					x++;
				}
				system("cls");
				break;
				
			case 3:
				system("cls");
				Cabecalho();
				printf("\n  Informe o resultado do jogo \n  Santos: ");
				scanf("%d", &resultado[1]);
				printf("  Bahia: ");
				scanf("%d", &resultado[2]);
							
				system("cls");
				Cabecalho();
				printf("\n   Resultado do Jogo: Santos \x1B[1m\x1B[32m %d x %d \x1B[0m Bahia \n", resultado[1], resultado[2]);
				printf("   Resultado do Bolao: \n");
				
				for (x = 1; x <= qtdPessoas; x++){
					// Acertou vencedor
					if (((palpite[x][1] > palpite[x][2]) && (resultado[1] > resultado[2])) || ((palpite[x][1] < palpite[x][2]) && (resultado[1] < resultado[2]))){
						// acertou placar exato
						if ((palpite[x][1] == resultado[1]) && (palpite[x][2] == resultado[2])){
							palpite[x][3] = 20;
						} else if (palpite[x][1] == resultado[1]){
							palpite[x][3] = 15;
						} else {
							palpite[x][3] = 10;
						}
					} else {
						if ((palpite[x][1] == resultado[1]) || (palpite[x][2] == resultado[2])){
							palpite[x][3] = 5;
						} else {
							palpite[x][3] = 0;
						}
					}
				}
				
				printf("\n");
					
				for (x = 1; x <= qtdPessoas; x++){
					printf("    - %s [%d x %d] ", jogador[x], palpite[x][1], palpite[x][2]);
					printf("    - %d pontos \n", palpite[x][3]);
				}
				
				printf("\n\n");
				system("pause");
				break;
		}
	}
}
