#include <stddef.h>

#define fileName "bankData.dat"
#define ENCRYPTION_KEY 123

typedef struct{
	int accNum;
	char name[50];
	float balance;
}Account;

void createAccount();
void displayAccounts();
void depositMoney();
void withdrawMoney();
void encryptDecrypt(char *data, size_t len);
void updateBalance(int accNum, float amount, int isDeposit);
