#include <stdio.h>
#include <limits.h>
int main(){
    int n,i,time=0,complete=0;
    int at[10],bt[10],pr[10],rt[10];
    int ct[10],tat[10],wt[10];
    float avgwt=0,avgtat=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter AT BT Priority of P%d: ",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i];
    }
    while(complete != n){
        int highest=-1;
        int min=INT_MAX;
        for(i=0;i<n;i++){
            if(at[i] <= time && rt[i] > 0 && pr[i] < min){
                min = pr[i];
                highest = i;
            }
        }
        if(highest == -1){
            time++;
            continue;
        }
        rt[highest]--;
        time++;
        if(rt[highest] == 0){
            complete++;
            ct[highest] = time;
            tat[highest] = ct[highest] - at[highest];
            wt[highest] = tat[highest] - bt[highest];
            avgwt += wt[highest];
            avgtat += tat[highest];
        }
    }
    printf("\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage WT = %.2f",avgwt/n);
    printf("\nAverage TAT = %.2f",avgtat/n);
    return 0;
}
