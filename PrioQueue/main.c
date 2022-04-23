#include<stdio.h>
#include<stdlib.h>
#include "PrioQueue.h"

#define MAX 10;


int main(int argc, char* argv[]){
	int choice;
	int value;
	int num;
	int i;
	
	while (1){
		display();
		frontier();
		rearier();
		printf("\n1.Enqueue\n2.Dequeue\n3.isEmpty\n4.isFull\n5.clear\n6.Head\n7.Tail\n8.Display");
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			printf("Insert the element in queue : ");
			scanf("%d", &value);
			enqueue(value);
			break;
		case 2:
			printf("\nEnter element to delete : "); 
            scanf("%d",&value);
			dequeue(value);
			break;
		case 3:
			isEmpty();
			break;
		case 4:
			if(isFull())
				printf("Queue is Full");
			else
				printf("NO. There are  10 values that can be accomodated ");
			break;
		case 5:
			clear();
			system("cls");
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

