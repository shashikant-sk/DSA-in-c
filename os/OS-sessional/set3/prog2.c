#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int burstTime;
    int burstTimeRemaining;
    int arrTime;
    int pid;
    int entry;
    int exit;
    int inQueue;
    int isComplete;
    int priority;
} process;

void swapProcess(process *a, process *b)
{
    process ta, tb;
    ta = *a;
    tb = *b;
    *b = ta;
    *a = tb;
}

int front = -1, rear = -1, sz = 0;
process pq[500];

void pushQueue(process it)
{
    if (front == -1)
        front = 0;
    rear++;
    pq[rear] = it;
    sz++;
}

void popQueue()
{
    front++;
    sz--;
}

process queueFront()
{
    return pq[front];
}

int isEmpty()
{
    return sz == 0;
}

void priorityScheduling(process p[], int n)
{
    int time = 0, count = n;
    while (count)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrTime <= time && !p[i].inQueue && !p[i].isComplete)
            {
                pushQueue(p[i]);
                p[i].inQueue = 1;
            }
        }
        for (int i = front; i <= rear; i++)
            for (int j = front + 1; j <= rear; j++)
                if (pq[i].priority > pq[j].priority)
                    swapProcess(&pq[i], &pq[j]);
        if (!isEmpty())
        {
            process currP = queueFront();
            popQueue();
            currP.entry = time;
            time += currP.burstTimeRemaining;
            currP.burstTimeRemaining = 0;
            currP.isComplete = 1;
            currP.inQueue = 0;
            currP.exit = time;
            count--;
            for (int i = 0; i < n; i++)
                if (currP.pid == p[i].pid)
                    p[i] = currP;
        }
    }
}

int main()
{
    process p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].pid = i;
        printf("\nEnter arrival time for process %d: ", i);
        scanf("%d", &p[i].arrTime);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].burstTime);
        printf("Enter priority for process %d: ", i);
        scanf("%d", &p[i].priority);
        p[i].entry = -1;
        p[i].exit = -1;
        p[i].inQueue = 0;
        p[i].isComplete = 0;
        p[i].burstTimeRemaining = p[i].burstTime;
    }

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            if (p[i].arrTime > p[j].arrTime)
                swapProcess(&p[i], &p[j]);

    priorityScheduling(p, 5);

    double waitTime = 0;
    double turnTime = 0;
    double resTime = 0;

    for (int i = 0; i < 5; i++)
        for (int j = i + 1; j < 5; j++)
            if (p[i].exit > p[j].exit)
                swapProcess(&p[i], &p[j]);

    printf("\nOrder of completion => ");
    for (int i = 0; i < 5; i++)
    {
        printf("P%d ", p[i].pid);
        int tt = 0, wt = 0, rt = 0;
        tt = p[i].exit - p[i].arrTime;  // Turn Around time = Finish Time - Arrival Time
        wt = tt - p[i].burstTime;       // Waiting Time = Turn Around Time - Burst Time
        rt = p[i].entry - p[i].arrTime; // Response Time = Entry Time - Arrival Time
        waitTime += wt;
        turnTime += tt;
        resTime += rt;
    }
    
    printf("\n\nAverage wait time: %.2f\n", waitTime / 5);
    printf("Average response time: %.2f\n", resTime / 5);
    printf("Average turnaround time: %.2f\n", turnTime / 5);

    return 0;
}
