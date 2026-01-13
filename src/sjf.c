#include <stdio.h>
#include "scheduler.h"

void sjf(struct process p[], int n) {
    int completed = 0, time = 0;
    int is_done[MAX] = {0};

    while (completed < n) {
        int idx = -1;
        int min_bt = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && !is_done[i]) {
                if (p[i].burst_time < min_bt) {
                    min_bt = p[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
        } else {
            p[idx].waiting_time = time - p[idx].arrival_time;
            time += p[idx].burst_time;
            p[idx].turnaround_time = p[idx].waiting_time + p[idx].burst_time;
            is_done[idx] = 1;
            completed++;
        }
    }
}

