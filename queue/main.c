#include<stdio.h>
#include "queue.h"


#define MAX 10

int main(int argc, char* argv[]){
	int choice;
	int value;
	int num = 0;
	int i;
	
	while (1){
		display();
		frontier();
		rearier();
		printf("\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.clear\n6.Head\n7.Tail");
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("Insert the element in queue : ");
			scanf("%d", &value);
			enqueue(value);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			isEmpty();
			break;
		case 4:
			if(isFull())
				printf("Queue is Full");
			else
				printf("Queue is NOT Full ");
			break;
		case 5:
			clear();
			break;
		case 6:
			frontier();
			break;
		case 7:
			rearier();
			break;
		default:
		printf("Wrong choice n");
		}
	}    	
	return 0;
}
