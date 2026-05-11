#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter number of resource types: ");
    scanf("%d", &m);
    int allocation[n][m], maximum[n][m], need[n][m];
    int available[m], request[m];
    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d", &maximum[i][j]);
        }
    }
    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    int process;
    printf("\nEnter process number making request: ");
    scanf("%d", &process);
    printf("Enter Request Vector:\n");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &request[i]);
    }
    for(i = 0; i < m; i++)
    {
        if(request[i] > need[process][i])
        {
            printf("\nError: Process exceeded maximum claim.\n");
            return 0;
        }
    }
    for(i = 0; i < m; i++)
    {
        if(request[i] > available[i])
        {
            printf("\nResources not available. Process must wait.\n");
            return 0;
        }
    }
    for(i = 0; i < m; i++)
    {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }
    int work[m], finish[n], safeSeq[n];
    for(i = 0; i < m; i++)
    {
        work[i] = available[i];
    }
    for(i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    int count = 0;
    while(count < n)
    {
        int found = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }
                if(possible)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
        {
            break;
        }
    }
    if(count == n)
    {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");
        for(i = 0; i < n; i++)
        {
            printf("P%d", safeSeq[i]);
            if(i != n - 1)
            {
                printf(" -> ");
            }
        }
        printf("\nRequest can be granted immediately.\n");
    }
    else
    {
        printf("\nSystem is NOT in safe state.\n");
        printf("Request cannot be granted.\n");
    }
    return 0;
}
