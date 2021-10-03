// C code for priority scheduling (non-preemptive)
#include <stdio.h>
#include <stdbool.h>

void swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void solve(int n, int bt[], int p[], int wt[], int tat[], int ct[], int pno[])
{
	int t = 0;

	for (int i = 0; i < n; i++)
	{
		printf("process %d runs from %d to %d \n", pno[i], t, t + bt[i]);
		t = t + bt[i];
		ct[i] = t;
		wt[i] = ct[i] - bt[i];
	}

	for (int i = 0; i < n; i++)
		tat[i] = bt[i] + wt[i];
}

int main()
{
	int n, *p, *bt, *wt, *tat, *ct, *pno;
	int sum = 0;
	printf("Enter the number of processes:");
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int));
	bt = (int *)malloc(n * sizeof(int));
	wt = (int *)malloc(n * sizeof(int));
	tat = (int *)malloc(n * sizeof(int));
	ct = (int *)malloc(n * sizeof(int));
	pno = (int *)malloc(n * sizeof(int));

	printf("Enter the burst time and priority of the processes \n");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < n; i++)
	{
		pno[i] = i + 1;
		printf("Burst time for process %d:", i + 1);
		scanf("%d", &bt[i]);
		printf("Priority for process %d:", i + 1);
		scanf("%d", &p[i]);
		printf("\n");
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			if (p[j] > p[j + 1])
			{
				swap(&p[j], &p[j + 1]);
				swap(&bt[j], &bt[j + 1]);
				swap(&pno[j], &pno[j + 1]);
			}
		}
	}
	printf("The priority based non-preemptive scheduling for given process is as follows \n");
	printf("-------------------------------------------------------------\n\n");
	solve(n, bt, p, wt, tat, ct, pno);

	int sum_wt = 0, sum_tat = 0;
	printf("\t\tProcess\t\tBurst Time\tPriority\tWaiting Time\tTurn_Around Time\tCompletion Time\n");
	for (int i = 0; i < n; i++)
	{
		sum_wt += wt[i];
		sum_tat += tat[i];

		printf("\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", pno[i], bt[i], p[i], wt[i], tat[i], ct[i]);
	}
	printf("Average waiting time:%f sec\n", (float)sum_wt / n);
	printf("Average turn around time:%d sec\n", (float)sum_tat / n);

	return 0;
}
