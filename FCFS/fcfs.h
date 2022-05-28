struct average{
	float AveWait;
	float AveTurn;
};

typedef struct average ave;

int waitingTime(ave *t, int n, int arrival[], int burst_time[], int wait[]);
int turnAround(ave *t, int n,int arrival[], int burst_time[], int wait[], int tat[]);
int averageOutput(ave *t, int n,int arrival[], int burst_time[], int wait[], int tat[]);

