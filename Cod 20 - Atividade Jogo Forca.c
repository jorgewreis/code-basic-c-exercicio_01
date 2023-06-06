#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"

struct CadastroPessoa {
    char nome[50];
    int idade;
    float altura;
};

void Cabecalho(){
	system("cls");
	char mensagem[] = "\n\r "LIGHT GREEN"Atividade - Todos os direitos reservados.";
    int i;
    printf(LIGHT GREEN"\n carregando");
    for (i = 0; i < 6; i++){
    	printf(LIGHT GREEN".");
    	fflush(stdout);
    	usleep(500000);
	 }
	 system("cls");
    for (i = 0; mensagem[i] != '\0'; i++) {
        printf("%c", mensagem[i]);
        fflush(stdout);
        usleep(1000);
    }
}

void Menu(){
	printf(LIGHT GREEN"\n   Gestão de Pessoas \n");
	printf("   --------------------------------------------------------------------------------------------------------------------- \n\n"RESET);
}

int main() {
	 struct CadastroPessoa pessoa[10];
    int totalPessoas = 0;
    int i, opcao;
    char consulta[30];
     
	 setlocale(LC_ALL, "portuguese");
	 
	 system("cls");
    Cabecalho();
    sleep(1);
            
    opcao = 0;

    while (opcao != 4) {
    	  system("cls");
    	  Menu();
        printf("  [1] Cadastrar pessoa\n");
        printf("  [2] Listar pessoas cadastradas\n");
        printf("  [3] Buscar pessoa por nome\n");
        printf("  [4] Sair\n\n");
        printf(" Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (totalPessoas < 10) {
                    struct CadastroPessoa novaPessoa;
                    system("cls");
                    Menu();
						                      
                    printf(" Digite o nome da pessoa: ");
                    scanf("%s", novaPessoa.nome);

                    printf(" Digite a idade: ");
                    scanf("%d", &novaPessoa.idade);

                    printf(" Digite a altura: ");
                    scanf("%f", &novaPessoa.altura);

                    pessoa[totalPessoas] = novaPessoa;
                    totalPessoas++;

                    printf("\n Cadastro realizado com sucesso!\n\n");
                } else {
                    printf(" Não é possível adicionar mais cadastros.\n\n");
                }
                printf(" ... retornando ao menu inicial\n\n");
                sleep(1);
                break;
            case 2:
                if (totalPessoas > 0) {
                	  system("cls");
                    Menu();
                    for (i = 0; i < totalPessoas; i++) {
                        printf(" %2d. %s \n", i + 1, pessoa[i].nome);
                    }
                    printf("\n");
                } else {
                    printf(" Não há pessoas cadastradas.\n\n");
                }
                printf(" pressione qualquer tecla para voltar ao menu \n");
                fflush(stdout);
                _getch();
                break;
            case 3:
                if (totalPessoas > 0) {
                	  system("cls");
                    Menu();                 
						  printf(" Digite o nome da pessoa a pesquisar: ");
                    scanf("%s", consulta);
                    
                    for(i = 0; i < totalPessoas; i++){
                    	   if(strcmp(consulta, pessoa[i].nome) == 0){
                    	   	system("cls");
						   		Menu();
                    	   	printf(" Cadastro encontrado!\n\n");
								   printf(" > %s, %d anos, %.2fm \n\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].altura);
			  			      }
                    }
                    printf("\n");
                } else {
                    printf(" Nenhum cadastro encontrado.\n\n");
                }
                printf(" pressione qualquer tecla para voltar ao menu \n\n");
                fflush(stdout);
                _getch();
                break;                
            case 4:
                system("cls");
                printf("\n\r "LIGHT GREEN"Obrigado por utilizar nosso sistema.\n Programa desenvolvido por Jorge Reis - Todos os direitos reservados.\n\n"RESET);
                break;
            default:
                break;
        }
    }  
    return 0;
}
