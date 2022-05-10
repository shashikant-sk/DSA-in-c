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
} process;

int front = -1, rear = -1, sz = 0;
process *pq[500];

void pushQueue(process *it)
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

process *queueFront()
{
    return pq[front];
}

int isEmpty()
{
    return sz == 0;
}

void swapProcess(process *a, process *b)
{
    process ta, tb;
    ta = *a;
    tb = *b;
    *b = ta;
    *a = tb;
}

void roundRobbin(process p[], int n, int r)
{
    int time = 0, count = n;
    while (count)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrTime <= time && !p[i].inQueue && !p[i].isComplete)
            {
                pushQueue(&p[i]);
                p[i].inQueue = 1;
            }
        }
        process *currP = NULL;
        if (!isEmpty())
            currP = queueFront(), popQueue();
        if (currP->entry == -1)
            currP->entry = time;
        if (currP->burstTimeRemaining > r)
        {
            currP->burstTimeRemaining -= r;
            time += r;
            for (int i = 0; i < n; i++)
            {
                if (p[i].arrTime <= time && !p[i].inQueue && !p[i].isComplete)
                {
                    pushQueue(&p[i]);
                    p[i].inQueue = 1;
                }
            }
            pushQueue(currP);
        }
        else
        {
            time += currP->burstTimeRemaining;
            currP->burstTimeRemaining = 0;
            currP->isComplete = 1;
            currP->inQueue = 0;
            currP->exit = time;
            count--;
        }
    }
}

int main()
{
    int r = 0;
    printf("\nEnter time quantum for round robbin: ");
    scanf("%d", &r);
    process p[5];
    for (int i = 0; i < 5; i++)
    {
        p[i].pid = i;
        printf("\nEnter arrival time for process %d: ", i);
        scanf("%d", &p[i].arrTime);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].burstTime);
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

    roundRobbin(p, 5, r);

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
