#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char nomePessoa[20];
	int i;
	
	scanf("%s", &nomePessoa);
   i = strlen(nomePessoa);
	printf("%d caracteres", i);
	
}
