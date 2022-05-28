typedef struct node* Nodeptr;

typedef struct
{
	int count;
	Nodeptr top;
}STACK_HEAD;

typedef STACK_HEAD* Stack;
typedef float stackItem;

typedef struct node{
	stackItem data;
	Nodeptr next;
}STACK_NODE;

//STACKS
Stack newStack();
void freeStack(Stack s);
void push(Stack s,stackItem item);  
stackItem pop(Stack s); 
stackItem stackTop(Stack s);
int isEmpty(Stack s);
void display(Stack s);
//FOR POSTFIX AND EVALUATION
int Postfix(Stack s, char Infixdata[], char* Postfixdata);
float Evaluate(Stack s, char Postfixdata[]);
int precedence(char item);//for precedence
int Operators(char item);//for operators
int isDigit(char item);
int isAlpha(char item);

