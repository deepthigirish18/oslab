#include <stdio.h>
int main()
{
    int n, m, i, j, k;
    printf("Enter number of processes -- ");
    scanf("%d", &n);
    printf("Enter number of resources -- ");
    scanf("%d", &m);
    int alloc[n][m], request[n][m], avail[m];
    int finish[n], sequence[n];
    printf("\nEnter Allocation Matrix\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter allocation for P%d -- ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter Request Matrix\n");
    for(i = 0; i < n; i++)
    {
        printf("Enter request for P%d -- ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    printf("\nEnter Available Resources -- ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    int work[m];
    for(i = 0; i < m; i++)
    {
        work[i] = avail[i];
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
                int flag = 1;
                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag == 1)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] = work[k] + alloc[i][k];
                    }
                    printf("\nP%d is visited ( ", i);
                    for(k = 0; k < m; k++)
                    {
                        printf("%d ", work[k]);
                    }
                    printf(")");
                    sequence[count] = i;
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
    printf("\n\nOUTPUT\n");
    if(count == n)
    {
        printf("No Deadlock Detected\n");
        printf("Safe Sequence is -- ( ");
        for(i = 0; i < n; i++)
        {
            printf("P%d ", sequence[i]);
        }
        printf(")");
    }
    else
    {
        printf("Deadlock Detected\n");
        printf("Processes in Deadlock are -- ");
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                printf("P%d ", i);
            }
        }
    }
    printf("\n\n");
    printf("Process\tAllocation\tRequest\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);
        for(j = 0; j < m; j++)
        {
            printf("%d ", alloc[i][j]);
        }
        printf("\t\t");
        for(j = 0; j < m; j++)
        {
            printf("%d ", request[i][j]);
        }
        printf("\n");
    }
    printf("\nAvailable Resources : ");
    for(i = 0; i < m; i++)
    {
        printf("%d ", avail[i]);
    }
    return 0;
}
