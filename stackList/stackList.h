typedef struct node* nodeptr;

typedef struct{
	int count;
	nodeptr top;
}HEAD;


typedef struct node{
	int value;
	nodeptr next;
}NODE;

typedef HEAD* Stack;

Stack createStack();
void push(Stack s, int num);
void pop(Stack s);
int isEmpty(Stack s);
void clear(Stack s);
int top(Stack s);
void display(Stack s);
