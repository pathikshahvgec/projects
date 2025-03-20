#include <stdbool.h>

void addNewBook();
void registerBorrower();
void issueBook();
void returnBook();
void searchBook();

struct Book{
	int bookId;
	char title[20];
	char author[20];
	long ISBN;
	bool availaibility;
};

typedef struct Book Book;

struct Borrower{
	int borrowerId;
	char name[20];
	char contactInfo[20];
};

typedef struct Borrower Borrower;

struct BorrowingRecord{
	int bookId;
	int borrowerId;
	char issueDate[20];
	char dueDate[20];
};

typedef struct BorrowingRecord BorrowingRecord;

void appendToBookFile(Book *book);
void appendToBorrowerFile(Borrower *borrower);
bool bookAvailaible(int bookId);
bool borrowerAvailaible(int borrowerId);
void appendToBorrowingRecordFile(int bookId, int borrowerId);
void updateBookStatusToBorrowed(int bookId);
int  fetchBookId(char buffer[]);
int  fetchBorrowerId(char buffer[]);
bool fetchBookStatus(char buffer[]);
