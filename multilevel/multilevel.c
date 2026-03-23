#include <stdio.h>
#define MAX 50
int main() {
    int n;
    int PID[MAX], AT[MAX], BT[MAX], TYPE[MAX];
    int CT[MAX], TAT[MAX], WT[MAX], Start[MAX];
    int systemQ[MAX], userQ[MAX];
    int sysCount = 0, userCount = 0;
    int i, j, temp;
    int time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("\nProcess %d:\n", i+1);
        printf("PID: ");
        scanf("%d", &PID[i]);
        printf("Arrival Time: ");
        scanf("%d", &AT[i]);
        printf("Burst Time: ");
        scanf("%d", &BT[i]);
        printf("Type (0 = System, 1 = User): ");
        scanf("%d", &TYPE[i]);
    }
    for(i = 0; i < n; i++) {
        if(TYPE[i] == 0)
            systemQ[sysCount++] = i;
        else
            userQ[userCount++] = i;
    }
    for(i = 0; i < sysCount - 1; i++) {
        for(j = i + 1; j < sysCount; j++) {
            if(AT[systemQ[i]] > AT[systemQ[j]]) {
                temp = systemQ[i];
                systemQ[i] = systemQ[j];
                systemQ[j] = temp;
            }
        }
    }
    for(i = 0; i < userCount - 1; i++) {
        for(j = i + 1; j < userCount; j++) {
            if(AT[userQ[i]] > AT[userQ[j]]) {
                temp = userQ[i];
                userQ[i] = userQ[j];
                userQ[j] = temp;
            }
        }
    }
    for(i = 0; i < sysCount; i++) {
        int p = systemQ[i];

        if(time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }
    for(i = 0; i < userCount; i++) {
        int p = userQ[i];

        if(time < AT[p])
            time = AT[p];

        Start[p] = time;
        time += BT[p];
        CT[p] = time;

        TAT[p] = CT[p] - AT[p];
        WT[p] = TAT[p] - BT[p];
    }
    printf("\n\nPID\tAT\tBT\tTYPE\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            PID[i], AT[i], BT[i], TYPE[i],
            CT[i], TAT[i], WT[i]);
    }
    return 0;
}
