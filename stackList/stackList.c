#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "stacklist.h"

Stack createStack(){
	Stack s = (Stack)malloc(sizeof(HEAD));
	s->count = 0;
	s->top = NULL;
	
	return s;
}

nodeptr createNode(int a){
	nodeptr temp;
	temp = (nodeptr)malloc(sizeof(NODE));
	temp->value = a;
	temp->next = NULL;
	
	return temp;
}

void push(Stack s, int num){
	nodeptr temp = createNode(num);
	temp->next = s->top;
	s->top = temp;
	s->count = s->count + 1;
}

void pop(Stack s){
	nodeptr temp;
	temp = s->top;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;
}

int isEmpty(Stack s){
	return s->top==NULL;
}

void clear(Stack s){
	while(!isEmpty(s)){
		pop(s);
	}
	printf("\nCLEARED\n");
}

int top(Stack s){
	return s->top->value;
}

void display(Stack s){
	nodeptr ptr = s->top;
	printf("Elements in Stack: ");
	while(ptr!=NULL){
		printf("%d ",ptr->value);
		ptr = ptr->next;
	}
	printf("\nTop: %d\n",top(s));
}




