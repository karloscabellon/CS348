#include<stdio.h>
#include "hrrn.h"

void sortArrival(process *p, int n){
    process ctr;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                ctr = p[i];
                p[i] = p[j];
                p[j] = ctr;
            }
        }
    }
}

void RatioN(process *p, int n, int btS){
	int i;
	int time;
    float await = 0, atat = 0;
    float hrr;
	float ctr;
    
    printf("Process Arrival Burst  Waiting TurnAround\n");
    for (time = p[0].arrival; time < btS;) {
        hrr = -9999;
        int loc;
        for (i = 0; i < n; i++) {
            if (p[i].arrival <= time && p[i].status != 1) {
                ctr = (p[i].burst_time + (time - p[i].arrival)) / p[i].burst_time;
                if (hrr < ctr) {
                    hrr = ctr;
                    loc = i;
                }
            }
        }
        time += p[loc].burst_time;
        p[loc].wait = time - p[loc].arrival - p[loc].burst_time;
        p[loc].tat = time - p[loc].arrival;
        atat += p[loc].tat;
        p[loc].status = 1;
        await += p[loc].wait;
        
        printf("\np%d\t%d\t%d\t%d\t%d",p[loc].proc+1, p[loc].arrival, p[loc].burst_time, p[loc].wait,p[loc].tat);
    }
    
    float totalwait = await/n;
    float totaltat = atat/n;
    printf("\n\nAverage Waiting Time = %.2f\n", totalwait);
    printf("Average Turnaround Time = %.2f\n", totaltat);
    
    totalwait = 0;
    totaltat = 0;
}

