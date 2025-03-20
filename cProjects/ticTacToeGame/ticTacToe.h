#include <stdbool.h>

void displayBoardWithNumbers(char board[][3], int rows);
void displayBoard(char board[][3], int rows);
void findRowAndCol(int *row, int *col, int num);
bool diagCrossed(char board[][3]);
bool colCrossed(char board[][3]);
bool rowCrossed(char board[][3]);
bool checkResult(char board[][3], int rows);
