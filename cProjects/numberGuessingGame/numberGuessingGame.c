#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	printf("Welcome to Number Guessing Game!\n");
	printf("In this game, a number has already been selected randomly from [1, 100] and user has to find this number.\n");

	//Seed the random number generator with current time
	srand(time(NULL));
	int secretNum = (rand() % 100) + 1;
	//printf("Random number between 1 to 100 is : %d", secretNum);
	
	int guessedNum = -1;
	int lower = 1, higher = 100;
	while(secretNum != guessedNum)
	{
		printf("Please guess and enter a number between [%d, %d] including boundary numbers:\n", lower, higher);
		scanf("%d", &guessedNum);

		if(guessedNum > secretNum)
		{
			printf("Your guess is higher, Please guess lower number.\n\n");
			higher = guessedNum;
		}
		else if(guessedNum < secretNum)
		{
			printf("Your guess is lower, Please guess higher number.\n\n");
			lower = guessedNum;
		}
		else
		{
			printf("Your guess is correct and You win this game!\n");
		}
	}
	return 0;

}
