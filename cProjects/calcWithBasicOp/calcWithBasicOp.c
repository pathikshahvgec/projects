#include<stdio.h>
#include"calcWithBasicOp.h"

int main()
{
	char response;
do
{
	int num1, num2, result;
	char operation;

	printf("Enter First Number:");
	scanf("%d", &num1);

	printf("Enter Second Number:");
	scanf("%d", &num2);

	printf("Select any one perations from the list:\n");
	printf("1. For Addition - select '+'\n");
	printf("2. For Subtraction - select '-'\n");
	printf("3. For Multiplication - select '*'\n");
	printf("4. For Division- select '/'\n");

	scanf(" %c", &operation);
	switch(operation)
	{
		case '+':
			result = add(num1, num2);
			break;
		case '-':
			result = sub(num1, num2);
			break;
		case '*':
			result = mul(num1, num2);
			break;
		case '/':
			result = div(num1, num2);
			break;
		default:
			printf("Invalid Operation, Please Try Again");
		
	}	
 			if(result == -1)
                        {
                                printf("Division by Zero is not possible.");
                        }
			else
			{
				printf("%d is answer for %c operation\n", result, operation);
			}
		printf("If you want to proceed further, Enter 'y' ");
		scanf(" %c", &response);

	
}while(response == 'y' || response == 'Y');
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int mul(int num1, int num2)
{
	return num1 * num2;
}

int div(int num1, int num2)
{	
	if(num2 == 0)
	{
		return -1;
	}
	return num1 / num2;
}

