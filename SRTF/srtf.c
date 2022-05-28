#include<stdio.h>
#include "srtf.h"


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
}

int calculate(int p[], int n, int arrival[], int burst_time[],int wait[], int tat[]){
	int burst2[n];
	int i; 
	int j;
	int INT_MAX;
	int totalwait = 0;
	int totaltat = 0;
	for(i = 0; i < n; i++){
		burst2[i] = burst_time[i];
	}
	int complete = 0, t = 0, min = INT_MAX;
    int shortest = 0;
	int finish_time;
    int check = 0;
    
      while(complete != n){
            for (j = 0; j < n; j++) {
                if ((arrival[j] <= t) &&
                (burst2[j] < min) && burst2[j] > 0) {
                    min = burst2[j];
                    shortest = j;
                    check = 1;
                }
            }
            
            if (check == 0){
                t++;
                continue;
            }

            burst2[shortest]--;
           
            if (burst2[shortest] == 0) {

                complete++;
                check = 0;
                finish_time = t + 1;
                wait[shortest] = finish_time - burst_time[shortest] - arrival[shortest];
                if (wait[shortest] < 0)
                    wait[shortest] = 0;
            }
            min = burst2[shortest];
            if (min == 0)
                min = INT_MAX;

            t++;
        }
    
	
	for(i = 0; i < n; i++)
		tat[i] = burst_time[i] + wait[i];
		
	printf("Process Arrival Burst  Waiting TurnAround\n");
    
	for(i = 0; i < n; i++){
		totaltat += tat[i];
		totalwait += wait[i];
		printf("\np%d\t%d\t%d\t%d\t%d",p[i],burst_time[i], arrival[i], wait[i],tat[i]);
	}
	
	printf("\n");
    printf("Average Waiting Time: %.2f\n", (float)totalwait/(float)n);
    printf("Average Turnaround Time: %.2f\n", (float)totaltat/(float)n);	
    
    return 0;
}
