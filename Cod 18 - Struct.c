#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <windows.h>

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
	char mensagem[] = "\n\r "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.";
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
    
	 HWND hWnd = GetConsoleWindow(); // Obter o identificador da janela do console

    // Esconder a janela inicialmente
    ShowWindow(hWnd, SW_HIDE);

    // Obter o estilo atual da janela
    LONG_PTR style = GetWindowLongPtr(hWnd, GWL_STYLE);
    // Remover os estilos de borda, barra de título e barras de rolagem
    style = style & ~(WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_BORDER | WS_VSCROLL | WS_HSCROLL);
    // Definir o estilo da janela como WS_POPUP
    style = style | WS_POPUP;
    // Aplicar o novo estilo à janela
    SetWindowLongPtr(hWnd, GWL_STYLE, style);
    // Redesenhar a janela para refletir as mudanças de estilo
    SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_FRAMECHANGED | SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);

    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    // Obter o tamanho da janela
    RECT windowRect;
    GetWindowRect(hWnd, &windowRect);
    int windowWidth = 800;
    int windowHeight = 600;
    // Calcular as coordenadas para centralizar a janela
    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;
    // Centralizar a janela usando SetWindowPos
    SetWindowPos(hWnd, NULL, posX, posY, windowWidth, windowHeight, SWP_NOSIZE | SWP_NOZORDER);

	 for (i = 0; i <= 255; i += 10) {
        SetLayeredWindowAttributes(hWnd, RGB(0, 0, 0), i, LWA_ALPHA); // Definir transparência gradativa
        ShowWindow(hWnd, SW_SHOW);
        Sleep(50); // Aguardar um breve intervalo para o efeito gradativo
    }
 
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
