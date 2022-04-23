#include<stdio.h>

#define MAX 10

int queue_arr[MAX];
int rear = -1;
int front = -1;


void enqueue(int value){
	if(front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue_arr[rear] = value;
}

void dequeue(){
	int value;
	value = queue_arr[front];
	if(front == -1 || front > rear)
		printf("Queue is Empty");
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    else {
      front = (front + 1) % MAX;
    }
}
	
void isEmpty(){
	if(front < 0 || front > rear){
		printf("\nIs queue Empty? YES");
	}
	else{
		printf("\nQueue HAS VALUES");
	}
}	

int isFull() {
	 if ((front == rear + 1) || (front == 0 && rear == MAX - 1))
  		return 1;
	else
  		return 0;
}

void clear(){
	int i;
	for(i = front; i <= rear; i++){
		queue_arr[i] = '\0';//NULL
		}
	return;
}

void display(){
	int i;
    printf("\n\nElements in Queue: ");
		for(i = front; i <= rear; i++)
			printf("%d ", queue_arr[i]);
}

void frontier(){
	printf("\nHead: %d", queue_arr[front]);
}

void rearier(){
	printf("\nTail: %d", queue_arr[rear]);
}


