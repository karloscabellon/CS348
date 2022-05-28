#include<stdio.h>
#include "npp.h"

#define MAX 10

int main(){
	int p[MAX];
	int arrival[MAX];
	int pr[MAX];
	int pr2[MAX];
	int burst_time[MAX];
	int wait[MAX];
	int tat[MAX];
	int at[MAX];
	int n;
	int i;
	
	printf("No. of Processes: ");
 		scanf("%d", &n);
 	
 	printf("Enter Burst time==Arrival time==Priority: \n\n");
 	for(i = 0; i < n; i++)
	{
 		printf("P%d: ", i + 1);
 		printf("\nBurst time: ");
		scanf("%d", &burst_time[i]);
		printf("Arrival time: ");
		scanf("%d", &arrival[i]);
		printf("Priority: ");
		scanf("%d", &pr[i]);
	
		printf("\n");
		p[i] = i + 1;
	}
	nPrio(p,n,at,arrival,pr2,pr,burst_time,wait,tat);
	return 0;
}
