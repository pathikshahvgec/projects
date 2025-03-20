#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "toDoListArray.h"

int main()
{
	char *tasks[10], answer;
	int taskCount = 0, choice;
	bool display = true;

	printf("Welcome to To-Do-List!\n");

	while(display == true)
	{
		displayTasks(tasks, taskCount);

		printf("Please select one of the below options:\n");
		printf("1. Add task in To-Do-List.\n");
		printf("2. Remove task from To-Do-List.\n");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				addTask(tasks, taskCount);
				taskCount++;
				break;
			case 2:
				removeTask(tasks, taskCount);
				taskCount--;
				break;
			default:
				printf("Invalid option, Please enter valid option.\n");
				break;
		}

		displayTasks(tasks, taskCount);
		printf("Do you still want to continue? Press Y/N:");
		scanf(" %c", &answer);

		if(answer == 'y' || answer == 'Y')
		{
			display = true;
		}
		else
		{
			display = false;
			for (int i = 0; i < taskCount; i++) {
    free(tasks[i]);
}

		}
	}
}

void addTask(char *tasks[], int taskCount)
{
	char sentence[100];
	printf("Enter the task, which you want to do:");
	fgets(sentence, sizeof(sentence), stdin);

	sentence[strcspn(sentence, "\n")] = 0;
	tasks[taskCount] = malloc(strlen(sentence) + 1);
	if (tasks[taskCount] == NULL) {
    printf("Memory allocation failed!\n");
    return;
}
	strcpy(tasks[taskCount], sentence);

}

void removeTask(char *tasks[], int taskCount)
{
//found index of task, which needd to be removed
//copy all tasks to another temp holder except this task
//free all memory from original holder
//copy back all task from temp holder to original holder
//free all memory from temp holder

	char sentence[100];
	//char *found = NULL;

	printf("Please enter task, which need to be removed:\n");
	fgets(sentence, sizeof(sentence), stdin);

	sentence[strcspn(sentence, "\n")] = 0;

	//printf("%s\n", sentence);
	int index;

	for(index = 0; index< taskCount; index++)
	{
		char *found = strstr(tasks[index], sentence);
		if(found)
		{
			//free(tasks[index]);
			break;
		}

		//printf("%d\n", strcmp(sentence, tasks[index]));
	}

	if (index >= taskCount) {
    printf("Task not found!\n");
    return;
}

if (tasks[index] != NULL) {
    free(tasks[index]);
    tasks[index] = NULL;
}

for (int i = index; i < taskCount - 1; i++) {
    tasks[i] = tasks[i + 1];
}
tasks[taskCount - 1] = NULL;  // Prevent dangling pointer

	
}

/*int main() {
    char sentence[100];
    char *tasks[10];
    int taskCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the trailing newline character from fgets
    sentence[strcspn(sentence, "\n")] = 0;

    printf("%lld", strlen(sentence));
    tasks[0] = malloc(strlen(sentence)) + 1;
    strcpy(tasks[0], sentence);
    taskCount++;

    printf("You entered: %s\n", tasks[0]);
	
    displayTasks(tasks, taskCount);
    return 0;
}*/


void displayTasks(char *tasks[], int taskCount)
{
	if(taskCount == 0)
	{
		printf("You have 0 task in To-Do-List!\n");
		return;
	}
	
	printf("Please find your tasks below:\n");
	for(int index = 0; index < taskCount; index++)
	{
		if(tasks[index])
		{
			printf("Task number %d ----> %s", index + 1, tasks[index]);
		}
	}
}
