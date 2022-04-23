#include <stdio.h>
#include <stdlib.h>



//Karl Thomas T. Cabellon

void push(int *point, int where, int num);
void pop(int *point, int where);
int isEmpty();
void clear(int *point);
int top(int *point, int where);

 
int main(){
	int *point;
	point = (int*)malloc(sizeof(int));
	int i;
	int num = 0;
	int choice;
	int value;
	
	point = (int*)malloc(sizeof(int));
	
    while(1){	
    	printf("\n\nElements of the Stack: ");
	    for (i = 0; i < num; i++)
	    printf("%d ", point[i]);
		printf("\n\n1.Push\n2.Pop\n3.IsEmpty\n4.Clear\n5.Top?\n6.Exit");
		printf("\n\nEnter your choice(1-6):");
		scanf("%d",&choice);
		switch(choice){
		case 1: 
			printf("Enter value to push: ");
            scanf("%d", &value);
        	push(point, num, value);
            num++;
            break;
		case 2: 
			pop(point, num);
            num--;
			break;
		case 3: 
			if(isEmpty(num)){
	        	printf("\nIs stack empty? Yes\n");
			}else{
	        	printf("\nIs stack empty? No\n");
			}
            break;
		break;
		case 4: 
			clear(point);
            num = 0;
            break;
        case 5: 
			if(isEmpty(num)){
                printf("\nSTACK HAS NOTHING\n");
            }else{
				printf("\nTop: %d\n", top(point, num));			
			}
            break;
        case 6: 
			exit(0);
		default: 
			printf("\nWrong Choice!!");
		break;
		}
	}
	return 0;
}


void push(int *point, int where, int num){
    point[where] = num;
}
 
void pop(int *point, int where){
	point[where] = 0;
}

int isEmpty(int num){
	return num == 0 ? 1 : 0;
}

void clear(int *point){
    free(point);
}

int top(int *point, int where){
    return point[where - 1];
}


