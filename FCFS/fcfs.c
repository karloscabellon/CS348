#include<stdio.h>
#include "fcfs.h"

int waitingTime(ave *t, int n,int arrival[], int burst_time[], int wait[]){
	int i;
	int ctr = 0;
	float sum = 0;
	
	
	for(i = 0; i < n; i++){
		if(i == 0){
			wait[i] = arrival[i];
		}else{
			wait[i] = ctr - arrival[i];
		}
			
		ctr += burst_time[i];
		sum += wait[i];
	}
	t->AveWait  = sum/n;
}

int turnAround(ave *t, int n,int arrival[], int burst_time[], int wait[], int tat[]){
	int i, ctr = 0;
	float sum = 0;
	float AveTurn;  	
    for(i = 0; i < n; i++){
	        ctr += burst_time[i];
	        tat[i] = ctr - arrival[i];
	        sum += tat[i];
	    }

	    AveTurn = sum/n;
}

int averageOutput(ave *t,int n,int arrival[], int burst_time[], int wait[], int tat[]){
	int i;
	
	printf("Process Arrival Burst  Waiting TurnAround\n");
	
	for(i = 0; i < n; i++){
		tat[i] = burst_time[i] + wait[i];
		printf(" %d\t  %d\t %d\t %d \t%d\n", i+1,arrival[i], burst_time[i], wait[i], tat[i]);
	} 
	printf("Average Waiting Time = %.2f\n",t->AveWait);
	printf("Average TurnAround Time = %.2f\n",t->AveTurn);
	
}
