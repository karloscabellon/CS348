#include<stdio.h>
#include"rr.h"

#define MAX 10

int main(){
	int burst_time[MAX];
	int arrival[MAX];
	int temp[MAX];
	int n;
	int i;
	int quanTime;

	
 	printf("\nno. of process: ");
 		scanf("%d", &n);
 	printf("\nQuantom : ");
 		scanf("%d", &quanTime);
 	
 	
	subm(n, arrival, temp, burst_time);
	  	
    
    averageOutput(n,burst_time,arrival,temp,quanTime);
	
	return 0;
}
