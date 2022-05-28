#include<stdio.h>
#include "sjf.h"

#define MAX 20

int main(){
	int burst_time[MAX], wait[MAX], tat[MAX], arrival[MAX], p[MAX];
	int n;
	int i;
	ave t;

	
 	printf("no. of process: ");
 		scanf("%d", &n);
 	
 	printf("Enter Burst time & Arrival time: \n\n");
 		for(i = 0; i < n; i++){
 				printf("P%d: \n", i + 1);
 				printf("Burst time: ");
					 scanf("%d", &burst_time[i]);
				printf("Arrival time: ");
					 scanf("%d", &arrival[i]);
				printf("\n");
				p[i] = i + 1;
		}
	sortProc(p,n,arrival,burst_time);
	waitingTime(&t,n,arrival,burst_time, wait);
	turnAround(&t,n,arrival,burst_time,wait,tat);
	averageOutput(&t,p,n,arrival,burst_time,wait,tat);
}
