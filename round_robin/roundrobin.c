#include <stdio.h>
int main() {
    int n, tq;
    int at[20], bt[20], rem_bt[20];
    int ct[20], tat[20], wt[20];
    int time = 0, remain, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time for P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
    }
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);
    remain = n;
    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rem_bt[i] > 0 && at[i] <= time) {
                if(rem_bt[i] <= tq) {
                    time += rem_bt[i];
                    rem_bt[i] = 0;
                    ct[i] = time;
                    remain--;
                }
                else {
                    rem_bt[i] -= tq;
                    time += tq;
                }
            }
        }
    }
    float avg_wt = 0, avg_tat = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat/n);
    return 0;
}
