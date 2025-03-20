#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "lms.h"

int main()
{
	int choice;

	printf("Welcome to LMS!\n");
	printf("PLease choose any one option number from given below list:\n");
	printf("1. Add new book ---> Enter 1.\n");
	printf("2. Register new borrower ---> Enter 2.\n");
	printf("3. Issue book ---> Enter 3.\n");
	printf("4. Return book ---> Enter 4.\n");
	printf("5. Search book ---> Enter 5.\n");

	printf("\nPlease enter your choice:");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			addNewBook();
			break;
		case 2:
			registerBorrower();
			break;
		case 3:
			issueBook();
			break;
		case 4:
			returnBook();
			break;
		case 5:
			searchBook();
			break;
		default:
			printf("You have entered invalid option, Please try again!\n");
			break;
	}
}

void addNewBook()
{
	Book book;
	printf("Enter book id : ");
	scanf("%d", &book.bookId);
	printf("Enter title : ");
	scanf("%s", book.title);
	printf("Enter author : ");
	scanf("%s", book.author);
	printf("Enter ISBN : ");
	scanf("%ld", &book.ISBN);
	book.availaibility = true;

	appendToBookFile(&book);
}

void appendToBookFile(Book *book)
{
	FILE *fp = fopen("BookFile.txt", "a");
	if(!fp)
	{
		printf("File not opened successfully!\n");
		return;
	}
	fprintf(fp, "%d, %s, %s, %ld, %d\n", book->bookId, book->title, book->author, book->ISBN, book->availaibility);
	fclose(fp);
}

void registerBorrower()
{
	Borrower borrower;
	printf("Enter borrower id : ");
	scanf("%d", &borrower.borrowerId);
	printf("Enter name : ");
	scanf("%s", borrower.name);
	printf("Enter contact info : ");
	scanf("%s", borrower.contactInfo);

	appendToBorrowerFile(&borrower);
}

void appendToBorrowerFile(Borrower *borrower)
{
	FILE *fp = fopen("BorrowerFile.txt", "a");
	if(!fp)
	{
		printf("File not opened successfully!\n");
		return;
	}
	fprintf(fp, "%d, %s, %s\n", borrower->borrowerId, borrower->name, borrower->contactInfo);
	fclose(fp);
}

void issueBook()
{
	int bookId, borrowerId;

	printf("Enter book id : ");
	scanf("%d", &bookId);
	if(bookAvailaible(bookId))
	{
		printf("Enter borrower id : ");
		scanf("%d", &borrowerId);
		if(!(borrowerAvailaible(borrowerId)))
		{
			registerBorrower();
		}
		appendToBorrowingRecordFile(bookId, borrowerId);
		updateBookStatusToBorrowed(bookId);
	}
	else
	{
		printf("Sorry, this book is already borrowed!\n");
	}
}

void updateBookStatusToBorrowed(int bookId)
{
	char buffer[100], bookStr[10];


	sprintf(bookStr, "%d", bookId);
	FILE *fp = fopen("BookFile.txt", "r+");
	while(fgets(buffer, sizeof(buffer), fp))
	{
		char *found = strstr(buffer, bookStr);
		if(found)
		{
			int fetchedBookId = fetchBookId(buffer);
			if(fetchedBookId == bookId)
			{
				int len = strlen(buffer);
				buffer[len - 2] = '0';
				fprintf(fp, "%s\n", buffer);
			}
		}
	}
	fclose(fp);
}

void appendToBorrowingRecordFile(int bookId, int borrowerId)
{
	BorrowingRecord borrowingRecord;
	borrowingRecord.bookId = bookId;
	borrowingRecord.borrowerId = borrowerId;
	printf("Enter issue date : ");
	scanf("%s", borrowingRecord.issueDate);
	printf("Enter due date : ");
	scanf("%s", borrowingRecord.dueDate);

	FILE *fp = fopen("BorrowingRecordFile.txt", "a");
	fprintf(fp, "%d, %d, %s, %s\n", borrowingRecord.bookId, borrowingRecord.borrowerId, borrowingRecord.issueDate, borrowingRecord.dueDate);
	fclose(fp);
}

bool borrowerAvailaible(int borrowerId)
{
	char buffer[100], borrowerStr[10];

	sprintf(borrowerStr, "%d", borrowerId);
	
	FILE *fp = fopen("BorrowerFile.txt", "r");
	while(fgets(buffer, sizeof(buffer), fp))
	{
		char *found = strstr(buffer, borrowerStr);
		if(found)
		{
			int fetchedBorrowerId = fetchBorrowerId(buffer);
			if(fetchedBorrowerId == borrowerId)
			{
				return true;
			}
		}
	}
	fclose(fp);
	return false;
}

int fetchBorrowerId(char *s)
{
	char temp[10];
	int count = -1;
	int borrowerId;

	while(*s != ',')
	{
		count++;
		temp[count] = *s;
		s++;
	}

	sscanf(temp, "%d", &borrowerId);
	return borrowerId;
}

bool bookAvailaible(int bookId)
{
	//printf("Reached here!\n");
	char buffer[100], bookStr[10];

	sprintf(bookStr, "%d", bookId);
	
	//printf("%s\n", bookStr);
	FILE *fp = fopen("BookFile.txt", "r");
	while(fgets(buffer, sizeof(buffer), fp))
	{
		char *found = strstr(buffer, bookStr);
		if(found)
		{
			//printf("%s\n", buffer);
			int fetchedBookId = fetchBookId(buffer);
			//printf("%d---->%d\n", fetchedBookId, bookId);
			if(fetchedBookId == bookId)
			{
				bool status = fetchBookStatus(buffer);
				printf("%d--->status\n", status);
				return status;
			}
		}
	}
	fclose(fp);
	return false;
}

bool fetchBookStatus(char *s)
{
	int len = strlen(s);
	if(s[len - 2] == '1')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int fetchBookId(char *s)
{
	char temp[10];
	int count = -1;
	int bookId;

	while(*s != ',')
	{	
		count++;
		temp[count] = *s;
		s++;
	}

	sscanf(temp, "%d", &bookId);
	return bookId;

}

void returnBook()
{

}

void searchBook()
{

}
