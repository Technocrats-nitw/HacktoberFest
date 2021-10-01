// C code for round robin algorithm
#include <stdio.h>
#include <stdbool.h>

int tq = 3;

struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int *)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    //printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue *queue)
{
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

void solver(int n, int bt[], int at[])
{
    int l_bt[n];
    for (int i = 0; i < n; i++)
        l_bt[i] = bt[i];
    int complete = 0, t = 0, last = -1;
    struct Queue *ready_queue = createQueue(n);
    for (int i = 0; i < n; i++)
    {
        if (at[i] == 0)
            enqueue(ready_queue, i);
    }
    while (complete != n)
    {

        if (isEmpty(ready_queue))
        {
            last = t;
            t++;
            for (int i = 0; i < n; i++)
            {
                if (t >= at[i] && last < at[i])
                    enqueue(ready_queue, i);
            }
            continue;
        }
        int cur = front(ready_queue);
        dequeue(ready_queue);
        if (l_bt[cur] <= tq)
        {
            printf("process %d runs from %d to %d \n", cur + 1, t, t + l_bt[cur]);
            last = t;
            t = t + l_bt[cur];
            l_bt[cur] = 0;
            complete++;
            for (int i = 0; i < n; i++)
            {
                if (t >= at[i] && last < at[i])
                    enqueue(ready_queue, i);
            }
        }
        else
        {
            printf("process %d runs from %d to %d \n", cur + 1, t, t + tq);
            last = t;
            t = t + tq;
            l_bt[cur] -= tq;
            for (int i = 0; i < n; i++)
            {
                if (t >= at[i] && last < at[i])
                    enqueue(ready_queue, i);
            }
            enqueue(ready_queue, cur);
        }
    }
}

int main()
{
    int n, *bt, *at;
    int sum = 0;
    printf("Enter the number of processes:");
    scanf("%d", &n);
    printf("Enter the time quantum to be used in scheduling:");
    scanf("%d", &tq);
    bt = (int *)malloc(n * sizeof(int));
    at = (int *)malloc(n * sizeof(int));

    printf("Enter the arrival time and burst time of the processes \n");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("Burst time for process %d:", i + 1);
        scanf("%d", &bt[i]);
        printf("Arrival time for process %d:", i + 1);
        scanf("%d", &at[i]);
        printf("\n");
    }
    printf("The round robin scheduling for given process is as follows \n");
    printf("-------------------------------------------------------------\n\n");
    solver(n, bt, at);

    return 0;
}
