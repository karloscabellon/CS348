#include<stdio.h>
#include "npp.h"

int nPrio(int p[],  int n, int at[],int arrival[],int pr2[],int pr[], int burst_time[], int wait[], int tat[]){
	int cTime  = 0;    
    int allTime = 0; 
    int size = n; 
    int i = 0;
	
	for (i = 0; i < n; i++)
    {
        pr2[i] = pr[i];
        at[i] = arrival[i];
    }

    int lat = 0;
    for (i = 0; i < n; i++)
        if (arrival[i] > lat)
            lat = arrival[i];

    int mPrio = 0; 
    for (i = 0; i < n; i++)
        if (pr2[i] > mPrio)
            mPrio = pr2[i];
            
    int ai = 0;     
    int p1 = pr2[0]; 
    int p2 = pr2[0]; 

    int j = -1;
    while (size > 0 && cTime <= 1000)
    {
        for (i = 0; i < n; i++)
        {
            if ((at[i] <= cTime) && (at[i] != (lat + 10)))
            {
                if (pr2[i] != (mPrio + 1))
                {
                    p2 = pr2[i];
                    j = 1;

                    if (p2 < p1)
                    {
                        j = 1;
                        ai = i;
                        p1 = pr2[i];
                        p2 = pr2[i];
                    }
                }
            }
        }

        if (j == -1)
        {
            cTime = cTime + 1;
            continue;
        }
        else
        {
            wait[ai] = cTime - at[ai];
            cTime = cTime + burst_time[ai];
            tat[ai] = cTime - at[ai];
            at[ai] = lat + 10;
            j = -1;
            pr2[ai] = mPrio + 1;
            ai = 0;        
            p1 = mPrio + 1;
            p2 = mPrio + 1; 
            size = size - 1;
        }
    }
	printf("Process Priority Arrival Burst  Waiting TurnAround\n");
    for(i = 0; i < n; i++)
    {
        printf("\np%d\t%d\t%d\t%d\t%d\t%d", p[i], pr[i], arrival[i], burst_time[i], wait[i], tat[i]);
    }

    float totalwait = 0;  //Average waiting time
    float totaltat = 0; // Average Turn around time
    for (i = 0; i < n; i++)
    {
        totalwait = wait[i] + totalwait;
        totaltat = tat[i] + totaltat;
    }
    printf("\nAWT: %.2f", (float)totalwait/(float)n);
    printf("\nATT: %.2f\n", (float)totaltat/(float)n);
 
	return 0;
}

