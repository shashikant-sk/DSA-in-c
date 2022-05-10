#include <stdio.h>
#include <stdlib.h>
 
typedef struct
{
   int burstTime;
   int arrTime;
   int pid;
   int entry;
   int exit;
   int compTime;
   int turnAroundTime;
   int waitTime;
   int responseTime;
} process;
 
void swapProcess(process *a, process *b)
{
   process temp;
 
   temp.burstTime = a->burstTime;
   temp.arrTime = a->arrTime;
   temp.pid = a->pid;
 
   a->burstTime = b->burstTime;
   a->arrTime = b->arrTime;
   a->pid = b->pid;
 
   b->burstTime = temp.burstTime;
   b->arrTime = temp.arrTime;
   b->pid = temp.pid;
}
 
int main()
{
   int n, waitTime = 0, resTime = 0, turnTime = 0;
 
   printf("Enter the number of processes: ");
   scanf("%d", &n);
   process *p = (process *)malloc(sizeof(process) * n);
   for (int i = 0; i < n; i++)
   {
       p[i].pid = i;
       printf("Enter arrival time for process %d: ", i);
       scanf("%d", &p[i].arrTime);
       printf("Enter burst time for process %d: ", i);
       scanf("%d", &p[i].burstTime);
       p[i].entry = -1;
       p[i].exit = -1;
   }
 
   // FCFS Sorting
   for (int i = 0; i < n; i++)
   {
       for (int j = i + 1; j < n; j++)
       {
           if (p[i].arrTime > p[j].arrTime)
               swapProcess(&p[i], &p[j]);
           else if (p[i].arrTime == p[j].arrTime)
           {   // SJF sorting if there is a tie
               if (p[i].burstTime < p[j].burstTime)
                   swapProcess(&p[i], &p[j]);
           }
       }
   }
 
   // Calculating entry and exit times
   for (int i = 0; i < n; i++)
   {
       if (i == 0)
           p[i].entry = p[i].arrTime;
       else
       {
           if (p[i].arrTime <= p[i - 1].exit)
               p[i].entry = p[i - 1].exit;
           else
               p[i].entry = p[i].arrTime;
       }
       p[i].exit = p[i].entry + p[i].burstTime;
   }
  
   // Calculating the total arrival, turn around and response times
   for (int i = 0; i < n; i++)
   {
       p[i].turnAroundTime = p[i].exit - p[i].arrTime;  
 // Turn Around time = Finish Time - Arrival Time
       p[i].waitTime = p[i].turnAroundTime - p[i].burstTime; 
 // Waiting Time = Turn Around Time - Burst Time
       p[i].responseTime = p[i].entry - p[i].arrTime; 
 // Response Time = Entry Time - Arrival Time
 
       waitTime += p[i].waitTime;
       turnTime += p[i].turnAroundTime;
       resTime += p[i].responseTime;
   }
 
   printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
   for (int i = 0; i < n; i++) {
 
       printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
           p[i].pid, //Process ID
           p[i].arrTime, //Arrival Time
           p[i].burstTime, //Burst Time
           p[i].compTime, //Completion time       
           p[i].turnAroundTime, //Turnaround time
           p[i].waitTime, //Waiting time
           p[i].responseTime //Response time
       );
   }
 
   printf("\nTotal wait time: %d\n", waitTime);
   printf("Total response time: %d\n", resTime);
   printf("Total turnaround time: %d\n", turnTime);
 
   return 0;
}