#include <stdio.h>
#define MAX 10
typedef struct {
    int id;
    int weight;
    int execution_time;
    int remaining_time;
    float cpu_received;
} Task;
int main() {
    Task t[MAX];
    int n, total_time = 0;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter execution time and weight for Task %d: ", i + 1);
        scanf("%d %d", &t[i].execution_time, &t[i].weight);
        t[i].id = i + 1;
        t[i].remaining_time = t[i].execution_time;
        t[i].cpu_received = 0.0;
        total_time += t[i].execution_time;
    }
    printf("\nProportional Scheduling Order:\n");
    for(int time = 0; time < total_time; time++) {
        int selected = -1;
        float min_ratio = 1e9;
        for(int i = 0; i < n; i++) {
            if(t[i].remaining_time > 0) {
                float ratio = t[i].cpu_received / t[i].weight;
                if(ratio < min_ratio) {
                    min_ratio = ratio;
                    selected = i;
                }
            }
        }
        if(selected != -1) {
            printf("Time %d -> Task %d\n", time, t[selected].id);

            t[selected].remaining_time--;
            t[selected].cpu_received += 1.0;
        }
    }
    return 0;
}
