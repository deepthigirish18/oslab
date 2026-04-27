#include <stdio.h>
#define MAX 10
typedef struct {
    int id;
    int execution_time;
    int period;
    int remaining_time;
    int deadline;
} Task;
int main() {
    Task t[MAX];
    int n, time, hyperperiod = 1;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter execution time and period for Task %d: ", i + 1);
        scanf("%d %d", &t[i].execution_time, &t[i].period);
        t[i].id = i + 1;
        t[i].remaining_time = 0;
        t[i].deadline = 0;
    }
    for(int i = 0; i < n; i++) {
        hyperperiod *= t[i].period;
    }
    printf("\nEDF Scheduling Order:\n");
    for(time = 0; time < hyperperiod; time++) {
        for(int i = 0; i < n; i++) {
            if(time % t[i].period == 0) {
                t[i].remaining_time = t[i].execution_time;
                t[i].deadline = time + t[i].period;
            }
        }
        int selected = -1;
        int earliest_deadline = 1e9;
        for(int i = 0; i < n; i++) {
            if(t[i].remaining_time > 0 && t[i].deadline < earliest_deadline) {
                earliest_deadline = t[i].deadline;
                selected = i;
            }
        }
        if(selected != -1) {
            printf("Time %d -> Task %d\n", time, t[selected].id);
            t[selected].remaining_time--;
        } else {
            printf("Time %d -> Idle\n", time);
        }
    }
    return 0;
}
