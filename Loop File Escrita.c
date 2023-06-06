#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

#define LIGHT "\x1B[1m"
#define GREEN "\x1B[32m"
#define RESET "\033[0m"

char repetir;
char nome[10];
int i, j, linha;
FILE *arquivo;	

void Cabecalho(){
	system("cls");
	printf("\n "LIGHT GREEN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Matriz de notas e media "RESET"\n\n");
}

void Repetir(){
	scanf(" %c", &repetir);
	repetir = tolower(repetir);
}

void NewFile() {
    FILE *arquivo = fopen("atvNome.txt", "r");
    FILE *alterado = fopen("atvTemporario.txt", "w");
    
    if (arquivo == NULL || alterado == NULL) {
        printf("Erro ao abrir arquivos\n");
        return;
    }
    
    unsigned int linha_selecionada = linha;
    unsigned int linha_atual = 1;
    char nome[50];
    
    while (fgets(nome, 50, arquivo) != NULL) {
        if (linha_atual != linha_selecionada) {
            fputs(nome, alterado);
        }
        memset(nome, 0, sizeof(char) * 50);
        linha_atual += 1;
    }
    
    fclose(arquivo);
    fclose(alterado);
    
    if (remove("atvNome.txt") != 0) {
        printf("Erro ao deletar arquivo\n");
        return;
    }
    
    if (rename("atvTemporario.txt", "atvNome.txt") != 0) {
        printf("Erro ao renomear arquivo\n");
        return;
    }
}


void Cadastrar(){
	if (repetir == 's'){
		do {
			Cabecalho();
			printf(" Digite um nome: \n ");
			scanf("%s", nome);
			
			while(nome[i]) {
		     nome[i] = toupper(nome[i]);
	        i++;
	      }
	      i = 0;	      
     		arquivo = fopen("atvNome.txt", "a");
			fputs(nome, arquivo);
			fputc('\n', arquivo);	
			
			printf("\n Deseja incluir outro nome? [s] Sim  ou [n] Não\n ");
			Repetir();
		} 
		while (repetir != 'n');
		fclose(arquivo);
	}
}

void Apagar(){
	if (repetir == 's'){
		arquivo = fopen("atvNome.txt", "a");
		if (repetir == 's'){
			Cabecalho();
			printf("\n Informe o número da linha para deletar o nome correspondente: ");
			scanf("%d", &linha);
			NewFile(linha);
		}
		fclose(arquivo);
	}
}

void Lista(){
	i = 1;
	printf(" LISTA DE NOMES: \n\n");
	arquivo = fopen("atvNome.txt", "r");
	while(fgets(nome, 50, arquivo) != NULL){
		printf("%2d. %s", i, nome);
		i++;
	}	
	fclose(arquivo);
}

int main (int argc, char *argv[]){
	setlocale(LC_ALL, "portuguese");
	
	Cabecalho();
	printf(" Deseja cadastrar algum nome? [s] Sim  ou [n] Não\n ");
	Repetir();
	Cadastrar();
	
	Cabecalho();
	Lista();		
	printf("\n Deseja apagar algum nome da lista? [s] Sim  ou [n] Não\n ");
	Repetir();
	Apagar();	
}
