#include <stdio.h>
int main() {
    int n, i, j, pos;
    int at[10], bt[10], ct[10], tat[10], wt[10];
    float avgwt = 0, avgtat = 0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Arrival Time and Burst Time of P%d: ",i+1);
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j] < bt[pos])
                pos=j;
        }
        int temp;
        temp=bt[i]; bt[i]=bt[pos]; bt[pos]=temp;
        temp=at[i]; at[i]=at[pos]; at[pos]=temp;
    }
    ct[0]=at[0]+bt[0];
    for(i=1;i<n;i++){
        ct[i]=ct[i-1]+bt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avgwt+=wt[i];
        avgtat+=tat[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\nAverage Waiting Time = %.2f",avgwt/n);
    printf("\nAverage Turnaround Time = %.2f",avgtat/n);
    return 0;
}
