#include <stdio.h>
#include <math.h>

#define KGRN "\x1B[32m"
#define RESET "\033[0m"

void Cabecalho(){
	system("cls");
	printf("\n "KGRN"Programa desenvolvido por Jorge Reis - Todos os direitos reservados.");
	printf("\n - Numeros pares menores que o informado "RESET"\n\n");
}

int main() {
    double a, b, c, discriminante, raiz1, raiz2;

	 Cabecalho();
    printf("Digite os coeficientes da equacao (a, b, c): ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminante = b * b - 4 * a * c;

    if (discriminante > 0) {
        raiz1 = (-b + sqrt(discriminante)) / (2 * a);
        raiz2 = (-b - sqrt(discriminante)) / (2 * a);
        printf("As raizes da equacao sao: %.2lf e %.2lf\n", raiz1, raiz2);
    }
    else if (discriminante == 0) {
        raiz1 = raiz2 = -b / (2 * a);
        printf("A equacao possui raizes iguais: %.2lf e %.2lf\n", raiz1, raiz2);
    }
    else {
        double parteReal = -b / (2 * a);
        double parteImaginaria = sqrt(-discriminante) / (2 * a);
        printf("A equacao possui raizes imaginarias: %.2lf + %.2lf e %.2lf - %.2lf\n",
            parteReal, parteImaginaria, parteReal, parteImaginaria);
    }

    return 0;
}

