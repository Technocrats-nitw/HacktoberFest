// C code for preemptive SJF algorithm
#include <stdio.h>
#include <stdbool.h>

void solve(int n, int bt[], int at[], int wt[], int tat[], int ct[], int p[])
{
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = bt[i];

    int complete = 0, t = 0, minm = 1e9;
    int shortest = 0, finish_time;
    bool check = false;

    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0)
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (check == false)
        {
            t++;
            continue;
        }
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0)
            minm = 1e9;
        printf("process %d runs from %d to %d \n", p[shortest], t, t + 1);
        if (rt[shortest] == 0)
        {

            ct[shortest] = t + 1;
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - bt[shortest] - at[shortest];
            if (wt[shortest] < 0)
                wt[shortest] = 0;
        }
        t++;
    }

    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

int main()
{
    int n, *p, *bt, *wt, *at, *tat, *ct;
    int sum = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    p = (int *)malloc(n * sizeof(int));
    bt = (int *)malloc(n * sizeof(int));
    wt = (int *)malloc(n * sizeof(int));
    at = (int *)malloc(n * sizeof(int));
    tat = (int *)malloc(n * sizeof(int));
    ct = (int *)malloc(n * sizeof(int));

    printf("Enter the arrival time and burst time of the processes  \n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("Burst time for process %d:", i + 1);
        scanf("%d", &bt[i]);
        printf("Arrival time for process %d:", i + 1);
        scanf("%d", &at[i]);
    }

    printf("The preemptive Shortest Job First (SJF) scheduling for given process is as follows \n");
    printf("-------------------------------------------------------------\n\n");
    solve(n, bt, at, wt, tat, ct, p);

    int sum_wt = 0, sum_tat = 0;
    printf("\n\n\t\tProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurn_Around Time\tCompletion Time\n");
    for (int i = 0; i < n; i++)
    {
        sum_wt += wt[i];
        sum_tat += tat[i];

        printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i], ct[i]);
    }
    printf("Average waiting time:%f sec\n", (float)sum_wt / n);
    printf("Average turn around time:%d sec\n", (float)sum_tat / n);

    return 0;
}
