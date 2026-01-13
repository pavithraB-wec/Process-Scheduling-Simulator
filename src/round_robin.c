#include <stdio.h>
#include "scheduler.h"

void round_robin(struct process p[], int n, int quantum) {
    int time = 0, completed = 0;

    for (int i = 0; i < n; i++)
        p[i].remaining_time = p[i].burst_time;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].remaining_time > 0 && p[i].arrival_time <= time) {

                if (p[i].remaining_time > quantum) {
                    time += quantum;
                    p[i].remaining_time -= quantum;
                } else {
                    time += p[i].remaining_time;
                    p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
                    p[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }
}
