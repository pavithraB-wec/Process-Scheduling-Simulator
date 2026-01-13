#include <stdio.h>
#include "scheduler.h"

void read_processes(struct process p[], int *n) {
    FILE *fp = fopen("input/processes.txt", "r");
    if (!fp) {
        printf("Error opening input file\n");
        return;
    }

    fscanf(fp, "%d", n);
    for (int i = 0; i < *n; i++) {
        fscanf(fp, "%d %d %d",
               &p[i].pid,
               &p[i].arrival_time,
               &p[i].burst_time);
    }
    fclose(fp);
}

void print_table(struct process p[], int n) {
    float awt = 0, atat = 0;

    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival_time,
               p[i].burst_time,
               p[i].waiting_time,
               p[i].turnaround_time);

        awt += p[i].waiting_time;
        atat += p[i].turnaround_time;
    }

    printf("\nAverage Waiting Time = %.2f", awt / n);
    printf("\nAverage Turnaround Time = %.2f\n", atat / n);
}

int main() {
    struct process p[MAX];
    int n, choice, quantum;

    read_processes(p, &n);

    printf("\nPROCESS SCHEDULING SIMULATOR\n");
    printf("1. FCFS\n2. SJF (Non-Preemptive)\n3. Round Robin\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            fcfs(p, n);
            break;
        case 2:
            sjf(p, n);
            break;
        case 3:
            printf("Enter Time Quantum: ");
            scanf("%d", &quantum);
            round_robin(p, n, quantum);
            break;
        default:
            printf("Invalid choice\n");
            return 0;
    }

    print_table(p, n);
    return 0;
}
