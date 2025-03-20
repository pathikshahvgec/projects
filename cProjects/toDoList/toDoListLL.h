struct Node {
	char *taskName;
	struct Node *next;
};

typedef struct Node Node;

Node* displayTasks(Node *node);
Node* addTask(Node *node);
Node* removeTask(Node *node);
Node* matchingNode(Node *node, char str[]);
Node* findPrevNode(Node *node, Node *temp);
void  freeAllMem(Node *node);
