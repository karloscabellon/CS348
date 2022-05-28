#include<stdio.h>
#include "rr.h"

void subm(int n, int arrival[], int temp[], int burst_time[]){
	int i;
	int ctr;
	
	ctr = n;
	
	for(i = 0; i < n; i++){
	    printf("\nP%d\n", i + 1);
	    printf("Input burst time: ");	
	    scanf("%d", &burst_time[i]);
	    printf("Input arrival time:");
	    scanf("%d", &arrival[i]);	
	    temp[i] = burst_time[i];
	}
}

void averageOutput(int n, int burst_time[], int arrival[], int temp[], int quanTime){
	int i;
	int total = 0, ctr = n, counter = 0, wait = 0, tat = 0;
	float totalwait, totaltat;
	
	printf("Process Arrival  Burst  Waiting TurnAround\n");
	for(i = 0; ctr != 0;)
	{
		
	    if(temp[i] <= quanTime && temp[i] > 0){
	          total += temp[i];
	          temp[i] = 0;
	          counter = 1;
	    }
	    else if(temp[i] > 0){
	          temp[i] = temp[i] - quanTime;
	          total += quanTime;
	    }	    
	    
	    if(temp[i] == 0 && counter == 1)
	    {
	        wait += total - arrival[i] - burst_time[i];
	        tat += total - arrival[i];
	        printf("P%d\t  %d\t %d\t %d \t%d\n", i + 1,arrival[i], burst_time[i], wait, tat);
	        
	        ctr--;
	        counter = 0;
	    }
	    
        if(i == n - 1)
     		i = 0;
	    else if(arrival[i + 1] <= total)
	       	i++;
	    else
	       	i = 0;
	    
	}
      
      totalwait = (float)wait * 1.0 / n;
      totaltat = (float)tat * 1.0 / n;
      
      printf("\n\nAverage Waiting Time:\t%.2f", totalwait);
      printf("\nAvg Turnaround Time:\t%.2f\n", totaltat);
}
