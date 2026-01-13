void fcfs(struct process p[], int n) {
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival_time)
            time = p[i].arrival_time;

        p[i].waiting_time = time - p[i].arrival_time;
        time += p[i].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
    }
}
