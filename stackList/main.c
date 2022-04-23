#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "stackList.h"

int main(){
	Stack s = createStack();
	int choice;
	int value;
	int i;
	
	
	while (1){
		printf("\n=====STACK MENU=====\n");
		printf("\n1.Display\n2.push\n3.pop\n4.isEmpty\n5.clear\n6.top");
		printf("\n\nEnter your choice : ");
		scanf("%d", &choice);
		switch(choice){
		case 1:
			display(s);
			break;
		case 2:
			printf("Insert the element in stack: ");
			scanf("%d", &value);
			push(s,value);
			break;
		case 3:
			pop(s);
			break;
		case 4:
			if(isEmpty(s))
				printf("is the stack Empty? Yes");
			else
				printf("Stack has values");
			break;
		case 5:
			clear(s);
			break;
		case 6:
			top(s);
			break;
		default:
			printf("Wrong choice n");
		}
	}    	
	return 0;
}
