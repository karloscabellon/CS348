#include<stdio.h>
#include<stdlib.h>
#include "PrioQueue.h"

#define MAX 10

int queue_arr[MAX];
int front = -1;
int rear = -1;

void insertion_sort(int item){
	int i;
	int j;  
    for (i = 0; i <= rear; i++) {	 
        if (item >= queue_arr[i]){ 
        	for (j = rear + 1; j > i; j--) { 
                queue_arr[j] = queue_arr[j - 1]; 
            } 
            	queue_arr[i] = item; 
           		return; 
        } 
    } 
    queue_arr[i] = item; 
}

void enqueue(int item){
	if(rear == -1){
		rear = front = 0;
		queue_arr[0] = item;
	}	
	else if(rear == MAX - 1){
		printf("\nQueue is FULL");
	}
	else{
		insertion_sort(item);
		rear++;
	}
}

void dequeue(int item){
 int i;
 for (i = 0; i <= rear; i++){ 
    if(item == queue_arr[i]){ 
        for (i; i < rear; i++){ 
                queue_arr[i] = queue_arr[i + 1]; 
            }
            rear--; 
            if (rear == -1) 
               front = -1; 
            return; 
        } 
	}
}

void display(){ 
    if(front == -1)
		printf("\nQueue is Empty");
	else
	{
		printf("\nElements in Queue: ");  
		int i = front;
		for(i = 0; i <= rear; i++){
			printf("%d ", queue_arr[i]);
		}
	}
}

void frontier(){
	printf("\nHead: %d", queue_arr[front]);
}

void rearier(){
	printf("\nTail: %d", queue_arr[rear]);
}

void isEmpty(){
	if(rear == -1 || front == -1){
		printf("\nIs queue Empty? YES");
	}
	else{
		printf("\nQueue HAS VALUES");
	}
}

int isFull(){
	if(rear == MAX - 1)
  		return 1;
	else
  		return 0;
}

int clear(){
	return front = -1, rear = -2;
}
