#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#define SIZE 30

int main(int argc, char *argv[]) {
	
	int i;
	int choice = 0;
	char Infixdata[SIZE];
	char Postfixdata[SIZE];
 	Stack s = newStack();
	
	do
	{
		system("cls");
		fflush(stdin);
		
		
		printf("Infix to Post Fix Conversion");
		printf("\nInfix String: ");
		fgets(Infixdata,SIZE,stdin);
				
		Postfix(s, Infixdata, Postfixdata);
		printf("Post Fix String: ");
		printf("%s", Postfixdata);
		
		printf("\n\nPostfix Evaluation");
		printf("\nPost Fix String: ");
		printf("%s",Postfixdata);
		printf("\nResult: %.2f", Evaluate(s, Postfixdata));
		
		
		
		freeStack(s);
		getchar();
	}while(choice == 1);
	return 0;
}

