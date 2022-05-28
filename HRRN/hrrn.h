typedef struct process {
    int proc;
    int arrival, burst_time, ct, wait, tat;
    int status;
}process;

void sortArrival(process *p, int n);
void RatioN(process *p, int n, int btS);

