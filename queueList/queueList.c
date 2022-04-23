#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "queueList.h"

Queue createQueue(){
	Queue q = (Queue)malloc(sizeof(HEAD));
	q->front = q->rear = NULL; //position all to NULL
	q->count = 0;//start count from zero
	q->MAX = 10;//index
}

nodeptr createNode(int a){
	nodeptr temp;
	temp = (nodeptr)malloc(sizeof(NODE));
	temp->element = a;
	temp->next = NULL;
	
	return temp;
}

void enqueue(Queue q, int num){
	nodeptr temp;
	temp = createNode(num);
	if(isFull(q)){
		printf("\nQueue is Full!");
	}
	if(isEmpty(q)){
		q->front = temp;
	}else
		q->rear->next = temp;
		q->rear = temp;
		q->count = q->count + 1;
}

void dequeue(Queue q){
	nodeptr temp;
	temp = q->front;
	if(q->count == 1)
		q->rear = NULL;
	q->front = q->front->next;
	temp->next = NULL;
	free(temp);
	q->count--;
}

int isEmpty(Queue q){
	return q->count == 0;
}

int isFull(Queue q){
	return q->count == q->MAX;// when count is equal to 10
} 

void clear(Queue q){
	while(!isEmpty(q)){
		dequeue(q);
	}
	printf("\nCLEARED");
}

int rear(Queue q){
	printf("\nTail: %d ", q->rear->element);
}

int front(Queue q){
	printf("\nHead: %d ", q->front->element);
}

void display(Queue q){
	nodeptr temp = q->front;
	printf("\nElements in Queue: ");
	while(temp != NULL){
		printf("%d ",temp->element);
		temp = temp->next;
	}
}



