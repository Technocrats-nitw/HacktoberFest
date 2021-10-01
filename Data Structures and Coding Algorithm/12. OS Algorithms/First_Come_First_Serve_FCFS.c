// C code for FCFS algorithm
#include <stdio.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void solver(int n, int bt[], int wt[], int at[], int tat[])
{
	int curr[n];
	curr[0] = at[0];
	wt[0] = 0;
	printf("process %d runs from %d to %d \n", 1, at[0], at[0] + bt[0]);
	for (int i = 1; i < n; i++)
	{
		curr[i] = curr[i - 1] + bt[i - 1];
		curr[i] = (curr[i] < at[i]) ? at[i] : curr[i];
		printf("process %d runs from %d to %d \n", i + 1, curr[i], curr[i] + bt[i]);
		wt[i] = curr[i] - at[i];
		if (wt[i] < 0)
			wt[i] = 0;
	}

	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

int main()
{
	int n, *bt, *wt, *at, *tat;
	int sum = 0;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	bt = (int *)malloc(n * sizeof(int));
	wt = (int *)malloc(n * sizeof(int));
	at = (int *)malloc(n * sizeof(int));
	tat = (int *)malloc(n * sizeof(int));

	printf("Enter the arrival time and burst time of the processes \n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		printf("Burst time for process %d:", i + 1);
		scanf("%d", &bt[i]);
		printf("Arrival time for process %d:", i + 1);
		scanf("%d", &at[i]);
		printf("\n\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (at[j] > at[j + 1])
			{
				swap(&at[j], &at[j + 1]);
				swap(&bt[j], &bt[j + 1]);
			}
		}
	}

	printf("The First Come First Serve(FCFS) scheduling for given process is as follows \n");
	printf("-------------------------------------------------------------\n\n");

	int sum_wt = 0, sum_tat = 0;
	solver(n, bt, wt, at, tat);
	printf("\n\n\t\tProcess\t\tBurst Time\tArrival Time\tWaiting Time\tTurn_Around Time\tCompletion Time\n");
	for (int i = 0; i < n; i++)
	{
		sum_wt += wt[i];
		sum_tat += tat[i];
		int ct = tat[i] + at[i];
		printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i], ct);
	}
	printf("Average waiting time:%f sec\n", (float)sum_wt / n);
	printf("Average turn around time:%d sec\n", (float)sum_tat / n);
	return 0;
}
