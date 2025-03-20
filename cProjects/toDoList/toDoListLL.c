#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "toDoListLL.h"

int main()
{
	Node *head = NULL;
	bool display = true;
	int choice;

	printf("Welcome to To-Do-List!\n");
	while(display == true)
	{
		head = displayTasks(head);

		printf("Please choose number from given below list.\n");
		printf("1. Add task - Enter 1.\n");
		printf("2. Remove task - Enter 2.\n");
		printf("3. Exit the Process - Enter 3.\n");
		printf("Enter your choice:");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				head = addTask(head);
				break;
			case 2:
				head = removeTask(head);
				break;
			case 3:
				display = false;
				//release all mem
				freeAllMem(head);
				break;
			default:
				printf("Invalid option entered, PLease try again!\n");
				break;
		}
	}
}

Node* displayTasks(Node *head)
{
	if(!head)
	{
		printf("You have 0 tasks in the List!\n");
		return NULL;
	}

	Node *curr = head;
	int count = 0;
	while(curr)
	{
		count++;
		printf("Task number : %d ---> %s\n", count, curr->taskName);
		curr = curr->next;
	}

	return head;
}

Node* addTask(Node *head)
{
	char sentence[100];

	printf("Enter your task : ");
	fgets(sentence, sizeof(sentence), stdin);
	sentence[strcspn(sentence, "\n")] = 0;

	Node *curr = NULL;

	curr = malloc(sizeof(Node));
	if(!curr)
	{
		printf("Memory allocation failed!\n");
		return head;
	}
	curr->taskName = malloc(strlen(sentence) + 1);
	if(!(curr->taskName))
	{
		printf("Memory allocation failed!\n");
		return head;
	}
	strcpy(curr->taskName, sentence);
	curr->next = NULL;

	if(head == NULL)
	{
		head = curr;
	}
	else
	{
		Node *temp = head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = curr;
	}

	return head;
}

Node* removeTask(Node *head)
{
	char sentence[100];

	printf("Enter task, which you want to remove :");
	fgets(sentence, sizeof(sentence), stdin);
	sentence[strcspn(sentence, "\n")] = 0;

	//find matching node for task
	//prev->next = node->next
	//free memoery first of char*, then node itself
	
	Node *delNode = matchingNode(head, sentence);
	if(delNode == head)
	{
		head = head->next;
		free(delNode->taskName);
		delNode->taskName = NULL;
		delNode->next = NULL;
		free(delNode);
		return head;
	}
	Node *prev = findPrevNode(delNode, head);
	{
		prev->next = delNode->next;
		free(delNode->taskName);
		delNode->taskName = NULL;
		delNode->next = NULL;
		free(delNode);
		return head;
	}
}

Node* findPrevNode(Node *delNode, Node *head)
{
	Node *curr = head;
	Node *prev = NULL;
	while(curr)
	{
		if(curr == delNode)
		{
			return prev;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}

	return prev;
}

Node* matchingNode(Node *head, char sentence[])
{
	Node *curr = head;
	while(curr)
	{
		char *found = strstr(curr->taskName, sentence);
		if(found)
		{
			return curr;
		}
		else
		{
			curr = curr->next;
		}
	}

	return curr;
}

void freeAllMem(Node *head)
{
	Node *curr = head;
	while(curr)
	{
		Node *temp = curr;
		free(temp->taskName);
		temp->taskName = NULL;
		curr = curr->next;
		free(temp);
	}
}
