#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Matriz de notas e media "RESET"\n\n");
}

void converterNome(char *str){
	int i = 0;
   while (str[i] != '\0') {
      str[i] = tolower(str[i]);
      i++;
   }
   if (str[0] >= 'a' && str[0] <= 'z') {
      str[0] = str[0] - 'a' + 'A';
   }	
}

int main() {
    setlocale(LC_ALL, "pt_BR");
	 char nomes[3][20];
    float notas[3][5] = {0};
    float media = 0;
    int x, y;
	 
    Cabecalho();

	 for (y = 1; y < 4; y++) {
 	   printf("\n Informe o nome do aluno %d: ", y);
 	   scanf("%19s", nomes[y]);
 	   converterNome(nomes[y]);
 	   media = 0;
   	   
	 	for (x = 1; x < 5; x++) {
        printf(" Informe a %da nota de %s: ", x, nomes[y]);
        scanf("%f", &notas[y][x]);
        media += notas[y][x];
      }
      
      notas[y][5] = media/4;
	 }
    

	 system("cls");
	 Cabecalho();

	 printf(" Boletim dos alunos: \n");
	 for (y = 1; y < 4; y++){
	 	printf("\n %d. %-15s", y, nomes[y]);
	 	for (x = 1; x < 5; x++) {	 		
		  printf("%10.2f", notas[y][x]);
      }
      printf("       ====  %5.2f", notas[y][5]);
	 }
    
    return 0;
}
