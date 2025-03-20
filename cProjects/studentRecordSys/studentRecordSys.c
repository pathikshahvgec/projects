#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studentRecordSys.h"

int main()
{
	int choice;

	printf("Welcome To Student Record System!\n");
	printf("Please select any one option from listed options below:\n");
	printf("1. Create new student record\n");
	printf("2. Read existing student record\n");
	printf("3. Update existing student record\n");
	printf("4. Delete existing student record\n");
	printf("Enter number from [1, 4] range as per your choice\n");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1:
			createRecord();
			break;
		case 2:
			readRecord();
			break;
		case 3:
			updateRecord();
			break;
		case 4:
			deleteRecord();
			break;
		default:
			printf("Invalid Entry, PLease try again!\n");
	}

	return 0;
}

void createRecord()
{
	char rollNo[10], name[10], country[10]; 
	printf("Please enter student's Roll no., Name and country seperated with space:\n");
	scanf("%s %s %s", rollNo, name, country);

	FILE *filep = fopen("records.txt", "a");
	fprintf(filep, "\n%s %s %s", rollNo, name, country);
	fclose(filep);
}

void readRecord()
{
	char rollNo[10];
	printf("Enter roll no. of student for record to be fetched.\n");
	scanf("%s", rollNo);

	FILE *filep = fopen("records.txt", "r");
	if(!filep)
	{
		perror("Error opening file\n");
	}
	
	int len = 100;
	char buffer[len];
	char *found = NULL;

	while(fgets(buffer, len, filep))
	{
		found = strstr(buffer, rollNo);
		if(found)
		{
			printf("%s\n", buffer);
			break;
		}

	}

	if(found == NULL)
	{
		printf("No Records Found for this Roll No.\n");
	}
	fclose(filep);
}


void updateRecord()
{
	deleteRecord();
	createRecord();
}


void deleteRecord()
{
	char rollNo[10];

	printf("Please enter Roll no. of stdent, whose record you want to update/delete.\n");
	scanf("%s", rollNo);

	char fileName[] = "records.txt";
	char tempFileName[] = "tempRecords.txt";

	FILE *filep = fopen(fileName, "r");
	if(!filep)
	{
		perror("Error opening the file!\n");
		return;
	}
	FILE *temp = fopen(tempFileName, "w");
	if(!temp)
	{
		perror("Error opening the file!\n");
		return;
	}
	
	int len = 100;
	char buffer[len];
	char *found = NULL;

	while(fgets(buffer, len, filep))
	{
		found = strstr(buffer, rollNo);
		if(found)
		{
			continue;
		}
		else
		{
			fprintf(temp, "%s", buffer);
		}
	}
	fclose(filep);
	fclose(temp);

	if(remove(fileName) != 0)
	{
		perror("Error deleting the original file!");
		return;
	}

	if(rename(tempFileName, fileName) != 0)
	{
		perror("Error renaming temporary file!");
		return;
	}

	printf("Record Deleted Successfully!\n");
}
