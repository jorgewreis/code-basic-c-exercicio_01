#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_PALAVRA 20  //DEFINIMOS O TAMANHO DA PALAVRA EM 20 CARACTERES COM A CONSTANTE.
#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"

// DEFININDO FUNÇÕES
void Abertura();
void Chuta() ;
void DesenhaForca();
void EscolhePalavra();
int Acertou();
int Enforcou() ;
int JaChutou(char letra);
void AdicionaPalavra();
int ChutesErrados();

// DEFININDO VARIÁVEIS
char palavraSecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesDados = 0;
int j;
int i;

// FUNÇÃO PARA ANIMAÇÃO DO BONECO AO INICIAR
void animacaoBoneco()
{
    printf("\n");

    for (i = 0; i < 3; i++)
    {
        printf("   O\n");
        printf("  /|\\\n");
        printf("  / \\\n\n");
        usleep(500000); // Aguarda 500ms
        system("cls");

        printf("  \\O/\n");
        printf("   |\n");
        printf("  / \\\n\n");
        usleep(500000); // Aguarda 500ms
        system("cls");
    }

    printf("\n");
}

// FUNÇÃO DE INICIO DO TEXTO DE ABERTURA
void Abertura(){
	system("cls");
	char mensagem[] = "\n\r "LIGHT GREEN"Atividade avaliativa em grupo";
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
    animacaoBoneco();    
}

void Menu(){
	printf(LIGHT GREEN"\n   JOGO DA FORCA \n");
	printf("   -------------------------------------------------------------------------------------------------------------- \n\n"RESET);
}

// FUNÇÃO PARA OBTER LETRA E INFORMAR SE JÁ FOI DIGITADA PELO USUÁRIO
void Chuta() {
    char chute;
    printf("\n   > ");
    scanf(" %c", &chute);
    chute = toupper(chute);

    // Verifica se a letra já foi digitada anteriormente
    if (JaChutou(chute)) {
        printf("   Essa letra já foi digitada anteriormente. Tente novamente.\n");
        sleep(2);
        return;
    }

    chutes[chutesDados] = chute;
    (chutesDados)++;
}

// FUNÇÃO QUE MOSTRA A FORCA, OS ERROS E ACERTOS
void DesenhaForca() {

    system("cls");
	 Menu();    
    int erros = ChutesErrados();

    printf("     __________       \n");
    printf("    |/          |     \n");

    printf("    |          %c%c%c  \n",  (erros >= 1 ? '(' : ' '),
        (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf("    |          %c%c%c  \n", (erros >= 3 ? '\\' : ' '),
     (erros >= 2 ? '|' : ' '),  (erros >= 3 ? '/' : ' '));
    printf("    |           %c     \n", (erros >= 2 ? '|' : ' '));
    printf("    |          %c %c   \n", (erros >= 4 ? '/' : ' '),
     (erros >= 4 ? '\\' : ' '));
    printf("    |                 \n");
    printf("    |                 \n");
    printf("   _|__               \n");
    printf("\n\n");
	 int achou;

    for (i = 0; i < strlen(palavraSecreta); i++){
        achou = JaChutou(palavraSecreta[i]);
        
		  
		  printf("   ");
        if (achou){
            printf("%c ", palavraSecreta[i]);
        } else {
            printf("_ ");
        }
    }
        
    printf("\n");
}

// FUNÇÃO PARA ADICIONAR NOVA PALAVRA AO DICIONÁRIO EXTERNO
void AdicionaPalavra()
{
    char quer;

    printf("   Você deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);
    quer = toupper(quer);

    if (quer == 'S')
    {
        char novapalavra[TAMANHO_PALAVRA];
        printf("Qual a nova palavra? ");
        scanf("%s", novapalavra);
        int t;
        for (t = 0; novapalavra[t] != '\0'; t++) {
        		novapalavra[t] = toupper(novapalavra[t]);
    	  }
        

        FILE *f = fopen("palavras.txt", "r+");

        if (f == NULL)
        {
            printf("   Desculpe, banco de dados não disponível\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

// FUNÇÃO PARA BUSCAR PALAVRA ALEATÓRIA NO DICIONÁRIO EXTERNO
void EscolhePalavra()
{
    FILE *f = fopen("palavras.txt", "r");

    if (f == NULL)
    {
        printf("   Desculpe, banco de dados não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for (i = 0; i <= randomico; i++)
    {
        fscanf(f, "%s", palavraSecreta);
    }

    fclose(f);
}

// FUNÇÃO QUE MOSTRA QUE O USUÁRIO GANHOU
int Acertou () {
    for (i = 0; i < strlen(palavraSecreta); i++) {
        if (!JaChutou(palavraSecreta[i]))
        {
           return 0;
        }  
    }
    return 1;
}

void MostraChutes() {
    printf("\n    Letras já digitadas: ");
    for (i = 0; i < chutesDados; i++) {
        printf("%c ", chutes[i]);
    }
    printf("\n");
}

int ChutesErrados() {
 int erros = 0;
    for(i = 0; i < chutesDados; i++) {
        int existe = 0;
        for ( j = 0; j < strlen(palavraSecreta); j++) {
           if (chutes[i] == palavraSecreta[j] ) {
            
            existe = 1;
            break;
           }    
        }
        
        if(!existe){
        	 erros++;
		  }
    }
    MostraChutes();
    return erros;
}

int Enforcou () {   
    return ChutesErrados() >= 5;
}

// FUNÇÃO PARA COMPARAR A LETRA DIGITADA COM A DA PALAVRA SECRETA
int JaChutou(char letra) {
    int achou = 0;
    for (j = 0; j < chutesDados; j++) {
        if (chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

// CÓDIGO PRINCIPAL
int main() {
	 setlocale(LC_ALL, "portuguese");
    EscolhePalavra(palavraSecreta);
    Abertura();
    Menu();

    do {
        DesenhaForca();
        Chuta();
    } while (!Acertou() && !Enforcou());

    if (Acertou()) {

	 DesenhaForca();
    printf("\n   Parabéns, você ganhou!\n\n ");

    printf("        ___________    \n");
    printf("        '._==_==_=_.'   \n");
    printf("        .-\\:      /-.  \n");
    printf("       | (|:.     |) |  \n");
    printf("        '-|:.     |-'   \n");
    printf("          \\::.    /    \n");
    printf("           '::. .'      \n");
    printf("             ) (        \n");
    printf("           _.' '._      \n");
    printf("           '""""""'     \n");


    } else {
        printf("   Você foi enforcado, tente novamente!");
        printf("   A palavra era **%s**\n\n", palavraSecreta);

        printf("      _______________   \n");
        printf("     /               \\  \n");
        printf("    /                 \\ \n");
        printf("   /                   \\ \n");
        printf("   |   XXXX     XXXX   |\n");
        printf("   |   XXXX     XXXX   |\n");
        printf("   |   XXX       XXX   |\n");
        printf("   |         X         |\n");
        printf("   \\__     XXX     __/ \n");
        printf("    |\\     XXX     /|   \n");
        printf("    | |           | |   \n");
        printf("    | I I I I I I I |   \n");
        printf("    |  I I I I I I  |   \n");
        printf("     \\_           _/    \n");
        printf("      \\_         _/     \n");
        printf("        \\_______/       \n\n");
    }
    
    AdicionaPalavra();
    
    // GRUPO:
    // JORGE WANDERLEY
    // LUCAS LIMA
    // JEFERSON GOMES
    
}
