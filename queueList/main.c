#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "queueList.h"

int main(){
	Queue q = createQueue();
	int choice;
	int value;
	int i;
	
	while (1){
		printf("\n1.Display\n2.Enqueue\n3.Dequeue\n4.isEmpty\n5.isFull\n6.clear\n7.Head\n8.Tail");
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			display(q);
			break;
		case 2:
			printf("Insert the element in queue : ");
			scanf("%d", &value);
			enqueue(q,value);
			break;
		case 3:
			dequeue(q);
			break;
		case 4:
			if (isEmpty(q))
				printf("\nIs queue empty? Yes");
			else
				printf("\nQUEUE has Values");
			break;
		case 5:
			if(isFull(q))
				printf("Queue is Full");
			else
				printf("Queue is NOT Full ");
			break;
		case 6:
			clear(q);
			break;
		case 7:
			front(q);
			break;
		case 8:
			rear(q);
			break;
		default:
		printf("Wrong choice");
		}
	}    	
	return 0;
}
