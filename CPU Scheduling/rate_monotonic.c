#include <stdio.h>
#define MAX 10
typedef struct {
    int id;
    int execution_time;
    int period;
    int remaining_time;
    int next_deadline;
} Task;
void sort_by_priority(Task t[], int n) {
    Task temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(t[i].period > t[j].period) {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}
int main() {
    Task t[MAX];
    int n, hyperperiod = 1, time = 0;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter execution time and period for Task %d: ", i + 1);
        scanf("%d %d", &t[i].execution_time, &t[i].period);
        t[i].id = i + 1;
        t[i].remaining_time = 0;
        t[i].next_deadline = 0;
    }
    for(int i = 0; i < n; i++) {
        hyperperiod *= t[i].period;
    }
    sort_by_priority(t, n);
    printf("\nScheduling Order:\n");
    for(time = 0; time < hyperperiod; time++) {
        for(int i = 0; i < n; i++) {
            if(time % t[i].period == 0) {
                t[i].remaining_time = t[i].execution_time;
                t[i].next_deadline = time + t[i].period;
            }
        }
        int selected = -1;
        for(int i = 0; i < n; i++) {
            if(t[i].remaining_time > 0) {
                selected = i;
                break;
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
