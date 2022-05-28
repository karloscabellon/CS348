#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"

Stack newStack(){
	Stack head = (Stack)malloc(sizeof(STACK_HEAD));
	head->count = 0;
	head->top = NULL;
	return head;
}

Nodeptr createNode(stackItem item){
	Nodeptr newNode = (Nodeptr) malloc(sizeof(STACK_NODE));
	newNode->data = item;
	newNode->next = NULL;
	return newNode;
}

void freeStack(Stack s){
	Nodeptr ptr = s->top;
	Nodeptr temp;
	while(ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
	s->count = 0;
	s->top = NULL;
}

void push(Stack s, stackItem item){
	Nodeptr newNode = createNode(item);
	newNode->next = s->top;
	s->top = newNode;
	s->count++;
}

stackItem pop(Stack s){
	stackItem tempData = s->top->data;
	Nodeptr temp = s->top;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;
	return tempData;
}

stackItem stackTop(Stack s){
	return s->top->data;
}

int isEmpty(Stack s){
	return s->count==0;
}

void display(Stack s){
	Nodeptr ptr = s->top;
	if(isEmpty(s) == 1) 
		printf("none");
	else
	{
		while(ptr != NULL) 
		{
			printf("%.2f, ", ptr->data);
			ptr = ptr->next;
		}
	}
}

int Operators(char item){
	
	if(item == '*' || item == '/' ||
	   item == '+' || item == '-'){
	   	
		return 1;
	   }
	else
		return 0;
}

int precedence(char item){
	int prec;
	
	if(item == '*' || item == '/'){
		prec = 2;
	}
	if (item == '+' || item == '-'){
		prec = 1;
	}
		return prec;
}

int isDigit(char item){
	return item >= '0' && item <= '9'; 
}

int isAlpha(char item){
	return (item >= 'a' && item <= 'z') || (item >= 'A' && item <= 'Z');	
}
int Postfix(Stack s, char Infixdata[], char* Postfixdata){
	int ctr;
	int ctr2 = 0;
	
	for(ctr = 0; Infixdata[ctr] != '\n'; ctr++)	{
		if(isAlpha(Infixdata[ctr])){ 
			printf("\nALPHA NOT ALLOWED\n");
			break;
		}
		else if(!Operators(Infixdata[ctr])){
			Postfixdata[ctr2++] = Infixdata[ctr];
		}
		else {
			while(!isEmpty(s) && precedence(stackTop(s)) >= precedence(Infixdata[ctr]))
				Postfixdata[ctr2++] = pop(s);
				push(s, Infixdata[ctr]);
		}
	}
	while(isEmpty(s) == 0){
		Postfixdata[ctr2++] = pop(s);
		Postfixdata[ctr2] = '\0';
	}
}

float Evaluate(Stack s, char Postfixdata[]){
	int ctr;
	float temp1;
	float temp2;
	float item;
		
	for(ctr = 0; Postfixdata[ctr] != '\0'; ctr++){
		if(Operators(Postfixdata[ctr]) == 0)
			push(s, Postfixdata[ctr] - '0');
			
		else 
		{
			temp1 = pop(s);
			temp2 = pop(s);
			switch(Postfixdata[ctr])
			{
				case '+':
					item = temp2 + temp1;
					break;
				case '-':
					item = temp2 - temp1;
					break;
				case '*':
					item = temp2 * temp1;
					break;
				case '/':
					item = temp2 / (float)temp1;
					break;
			}
			push(s, item);
		}
	}
	return pop(s);
}
