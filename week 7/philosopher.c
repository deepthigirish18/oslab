#include <stdio.h>
int main() {
    int n, hungry, pos[10];
    int choice, i, j;
    printf("Enter the total number of philosophers: ");
    scanf("%d", &n);
    printf("How many are hungry: ");
    scanf("%d", &hungry);
    for (i = 0; i < hungry; i++) {
        printf("Enter philosopher %d position (1 to %d): ", i + 1, n);
        scanf("%d", &pos[i]);
    }
    while (1) {
        printf("\n1. One can eat at a time\n");
        printf("2. Two can eat at a time\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 3)
            break;
        if (choice == 1) {
            printf("Allow one philosopher to eat at any time\n");
            for (i = 0; i < hungry; i++) {
                for (j = i; j < hungry; j++) {
                    printf("P %d is waiting\n", pos[j]);
                }
                printf("P %d is granted to eat\n", pos[i]);
                printf("P %d has finished eating\n", pos[i]);
            }
        }
        else if (choice == 2) {
            printf("Allow two philosophers to eat at any time\n");
            for (i = 0; i < hungry; i += 2) {
                for (j = i; j < hungry; j++) {
                    printf("P %d is waiting\n", pos[j]);
                }
                printf("P %d is granted to eat\n", pos[i]);
                printf("P %d has finished eating\n", pos[i]);
                if (i + 1 < hungry) {
                    printf("P %d is granted to eat\n", pos[i + 1]);
                    printf("P %d has finished eating\n", pos[i + 1]);
                }
            }
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}
