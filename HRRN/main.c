#include<stdio.h>
#include "hrrn.h"

#define MAX 10

int main(){
	int i;
	int j;
	int n;
	int t;
	int btS = 0;
    process p[MAX];
	
 	printf("No of Processes: ");
 		scanf("%d", &n);
 	
 	
 	printf("Enter Burst time==Arrival time: \n\n");
 	for(i=0; i<n; i++){	
		printf("\n");
	    printf("P%d: \n",i+1);
		printf("Burst Time: ");
		scanf("%d",&p[i].burst_time);
	    printf("Arrival Time: ");
	    scanf("%d",&p[i].arrival);
		    
		p[i].proc = i;
	    p[i].status = 0;
		btS += p[i].burst_time;
		}
	
	sortArrival(p,n);
	RatioN(p,n,btS);

	return 0;
}
