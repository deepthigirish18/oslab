#include <stdio.h>
#include <limits.h>
int main() {
    int n, i, time = 0, smallest;
    int at[10], bt[10], rt[10];
    int ct[10], wt[10], tat[10];
    int complete = 0;
    float avgwt = 0, avgtat = 0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter AT and BT of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
        rt[i]=bt[i];
    }
    while(complete != n){
        smallest = -1;
        int min = INT_MAX;
        for(i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0 && rt[i] < min){
                min = rt[i];
                smallest = i;
            }
        }
        if(smallest == -1){
            time++;
            continue;
        }
        rt[smallest]--;
        time++;
        if(rt[smallest] == 0){
            complete++;
            ct[smallest] = time;
            tat[smallest] = ct[smallest] - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];
            avgwt += wt[smallest];
            avgtat += tat[smallest];
        }
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);
    return 0;
}
