#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

int main(){
	srand(time(0));
	
	int maxNumber = 100;
	int secretNumber = rand() % maxNumber + 1;
	int numGuesses = 0;
	int guess;
	
	do {
		cout << "Advinhe o número entre 1 e " << maxNum << ": ";
		cin >> guess++;
		numGuesses++;
		
		if (guess < secretNumber){
			cout << "O número é maior que esse..." << endl;
		} else if (guess > secretNumber){
			cout << "O número é menor que esse..." << endl;
		} else {
			cout << "Parabéns, você acertou em " << numGuesses << " tentativas " << endl;
		}		
		
	} while (guess != secretNumber);
	
	return 0;
}
