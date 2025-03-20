#include <stdio.h>
#include "bms.h"

int main()
{
	int choice;

	do
	{
		printf("\n== Welcome to Bank Management System! ==\n");
		printf("Please choose any one option number from given below list:\n");

		printf("1. Create account...\n");
		printf("2. Display accounts...\n");
		printf("3. Deposit money...\n");
		printf("4. Withdraw money...\n");
		printf("5. Exit the process...\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				createAccount();
				break;
			case 2:
				displayAccounts();
				break;
			case 3:
				depositMoney();
				break;
			case 4:
				withdrawMoney();
				break;
			case 5:
				printf("Exiting... Thank you!\n");
				break;
			default:
				printf("Invalid choice! Please try again!\n");
		}
	}while(choice != 5);

	return 0;
}

void createAccount()
{
	Account acc;

	FILE *fp = fopen(fileName, "ab");
	if(!fp)
	{
		printf("Erroe opening the file!");
		return;
	}

	printf("Enter Account Number : ");
	scanf("%d", &acc.accNum);
	printf("Enter name : ");
	scanf(" %[^\n]", acc.name);
	printf("Enter Initial Deposit : ");
	scanf("%f", &acc.balance);

	encryptDecrypt((char*)&acc, sizeof(acc));

	fwrite(&acc, sizeof(Account), 1, fp);

	fclose(fp);

	printf("Account created successfully!\n");
}

void encryptDecrypt(char *data, size_t len)
{
	for(size_t i = 0; i < len; i++)
	{
		data[i] ^= ENCRYPTION_KEY;
	}
}


void displayAccounts()
{
	Account acc;

	FILE *fp = fopen(fileName, "rb");
	if(!fp)
	{
		printf("Error opening the file!\n");
		return;
	}

	printf("\n=== Account Details ===\n");
	while(fread(&acc, sizeof(Account), 1, fp))
	{
		encryptDecrypt((char*)&acc, sizeof(acc));
		printf("Account Number : %d\n", acc.accNum);
		printf("Name : %s\n", acc.name);
		printf("Balance : %.2f\n", acc.balance);
		printf("----------------------\n");
		encryptDecrypt((char*)&acc, sizeof(acc));
	}
	fclose(fp);
}

void depositMoney()
{
	int accNum;
	float amount;

	printf("Enter Account Number : ");
	scanf("%d", &accNum);
	printf("Enter Deposit Amount : ");
	scanf("%f", &amount);

	updateBalance(accNum, amount, 1);
}

void updateBalance(int accNum, float amount, int isDeposit)
{
	Account acc;
	
	int offset = sizeof(Account);

	FILE *fp = fopen(fileName, "rb+");
	if(!fp)
	{
		printf("Error opening the file!\n");
		return;
	}

	int found = 0;

	while(fread(&acc, sizeof(Account), 1, fp))
	{
		encryptDecrypt((char*)&acc, sizeof(acc));

		if(acc.accNum == accNum)
		{
			found = 1;
			if(!isDeposit && acc.balance < amount)
			{
				printf("Insufficient balance!\n");
			}
			else
			{
				acc.balance += (isDeposit ? amount : -amount);
				fseek(fp, -offset, SEEK_CUR);
				encryptDecrypt((char*)&acc, sizeof(acc));
				fwrite(&acc, sizeof(Account), 1, fp);
				printf("Transaction successful! \n");
			}
			break;
		}

		encryptDecrypt((char*)&acc, sizeof(acc));
	}

	if(!found)
	{
		printf("Account not found!\n");
	}
	fclose(fp);
}

void withdrawMoney()
{
	int accNum;
	float amount;

	printf("Enter Account Number : ");
	scanf("%d", &accNum);
	printf("Enter Withdrawal Amount : ");
	scanf("%f", &amount);

	updateBalance(accNum, amount, 0);
}
