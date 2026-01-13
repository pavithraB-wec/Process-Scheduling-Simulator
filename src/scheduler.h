#ifndef SCHEDULER_H
#define SCHEDULER_H

#define MAX 20

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};

void read_processes(struct process p[], int *n);
void print_table(struct process p[], int n);

void fcfs(struct process p[], int n);
void sjf(struct process p[], int n);
void round_robin(struct process p[], int n, int quantum);

#endif
