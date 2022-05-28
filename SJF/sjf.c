#include<stdio.h>
#include "sjf.h"

int sortProc(int p[],  int n, int arrival[], int burst_time[]){
	int i;
	int j;
	int ctr;
	int temp;
	
	for(i = 0; i < n; i++){ 
		ctr = i;
        for(j = i + 1; j < n; j++){
            if(arrival[j] < arrival[ctr])
            	ctr = j;
        }
    
        temp = arrival[i];
       	arrival[i] = arrival[ctr];
        arrival[ctr] = temp;
  		
  		temp = burst_time[i];
	    burst_time[i] = burst_time[ctr];
	    burst_time[ctr] = temp;
  		
        temp = p[i];
       	p[i] = p[ctr];
        p[ctr] = temp;
    }
    
    for(i = 0; i < n; i++){
		for(j = i + 1; j < n; j++){
			if(arrival[i] == arrival[j] && burst_time[i] > burst_time[j]){
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
				
				temp = arrival[i];
				arrival[i] = arrival[j];
				arrival[j] = temp;
				
				temp = burst_time[i];
				burst_time[i] = burst_time[j];
				burst_time[j] = temp;
			}
		}
	}
	return 0;
}

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

	t->AveTurn = sum/n;
}

int averageOutput(ave *t,int p[],int n,int arrival[], int burst_time[], int wait[], int tat[]){
	int i;
	
	printf("Process Arrival Burst  Waiting TurnAround\n");
	
	for(i = 0; i < n; i++){
		tat[i] = burst_time[i] + wait[i];
		printf(" %d\t  %d\t %d\t %d \t%d\n",p[i],arrival[i], burst_time[i], wait[i], tat[i]);
	} 
	printf("Average Waiting Time = %.2f\n",t->AveWait);
	printf("Average TurnAround Time = %.2f\n",t->AveTurn);
	
}
