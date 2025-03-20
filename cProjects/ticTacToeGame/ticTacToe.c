#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "ticTacToe.h"

int main()
{
	char board[3][3], markdown = 'O';
	bool gameOver = false;
	int choice, row, col, count = 0;

	printf("Welcome to Tic-Tac-Toe Game!\n");
	displayBoardWithNumbers(board, 3);

	while(gameOver == false)
	{
		if(markdown == 'O')
		{
			markdown = 'X';
		}
		else
		{
			markdown = 'O';
		}

		displayBoard(board, 3);

		printf("Please enter number availaible from grid to markdown with %c : ", markdown);
		scanf("%d", &choice);

		findRowAndCol(&row, &col, choice);

		board[row][col] = markdown;
		++count;

		gameOver = checkResult(board, 3);

		if(count == 9)
		{
			gameOver = true;
		}

	}

	return 0;
}

bool checkResult(char board[][3], int rows)
{
	return (rowCrossed(board) || colCrossed(board) || diagCrossed(board));
}

bool rowCrossed(char board[][3])
{
	for(int row = 0; row < 3; row++)
	{
		if(board[row][0] == board[row][1] && board[row][1] == board[row][2])
			return true;
	}

	return false;
}

bool colCrossed(char board[][3])
{
	for(int col = 0; col < 3; col++)
	{
		if(board[0][col] == board[1][col] && board[1][col] == board[2][col])
			return true;
	}

	return false;
}

bool diagCrossed(char board[][3])
{
	if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return true;
	}
	if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
	{
		return true;
	}

	return false;
}

void findRowAndCol(int *row, int *col, int num)
{
	*row = ceil(num / 3.0) - 1;
	if(*row < 0)
	{
		*row = 0;
	}

	if(num % 3 == 0)
	{
		*col = 2;
	}
	else
	{
		*col = (num % 3) - 1;
	}
}

void displayBoard(char board[][3], int rows)
{
	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			printf("%c|", board[row][col]);
		}
		printf("\n");
		for(int col = 0; col < 3; col++)
		{
			printf("_|");
		}
		printf("\n");
	}
}

void displayBoardWithNumbers(char board[][3], int rows)
{
	char count = '0';

	for(int row = 0; row < rows; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			board[row][col] = ++count;
			printf("%c|", board[row][col]);
		}
		printf("\n");
		for(int col = 0; col < 3; col++)
		{
			printf("_|");
		}
		printf("\n");
	}
}
