#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter number of process: ");
    scanf("%d",&n);
    int p[5],at[5],bt[5],prio[5],et[5],tat[5],wt[5],totalwt=0,totalrt=0,totaltat=0;
    for(int i=0;i<n;i++)
    {
        printf("\n----------PROCESS %d----------\n",i+1);
        printf("Enter burst time: ");
        scanf("%d",&bt[i]);
        printf("Enter arrival time: ");
        scanf("%d",&at[i]);
        p[i]=i+1;
        prio[5]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int t1,t2,t3,t4;
            if(at[i]>at[j])
            {
                t1=at[i];
                t2=bt[i];
                t3=p[i];
                t4=prio[i];
                at[i]=at[j];
                bt[i]=bt[j];
                p[i]=p[j];
                prio[i]=prio[j];
                at[j]=t1;
                bt[j]=t2;
                p[j]=t3;
                prio[j]=t4;
            }
        }
    }
    et[0]=at[0];
    for(int i=1;i<n;i++)
    {
        if(at[i]>(et[i-1]+bt[i-1]))
            et[i]=at[i];
        else
            et[i]=et[i-1]+bt[i-1];
    }
    for(int i=0;i<n;i++)
    {
        wt[i]=et[i]-at[i];
        tat[i]=wt[i]+bt[i];
    }
    for(int i=0;i<n;i++)
    {
        totalwt=totalwt+wt[i];
        totaltat=totaltat+tat[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int t1,t2,t3,t4,t5;
            if(p[i]>p[j])
            {
                t1=at[i];
                t2=bt[i];
                t3=p[i];
                t4=wt[i];
                t5=tat[i];
                at[i]=at[j];
                bt[i]=bt[j];
                p[i]=p[j];
                wt[i]=wt[j];
                tat[i]=tat[j];
                at[j]=t1;
                bt[j]=t2;
                p[j]=t3;
                wt[j]=t4;
                tat[j]=t5;
            }
        }
    }
    printf("\n--------------------------------------------------------------");
    printf("\n|PROCESS|ARRIVAL TIME|BURST TIME|WAITING TIME|TURNAROUND TIME|");
    printf("\n--------------------------------------------------------------");
    for(int i=0;i<n;i++)
    {
        printf("\n|   %d   |      %d     |     %d    |     %d     |      %d      |",p[i],at[i],bt[i],wt[i],tat[i]);
        printf("\n--------------------------------------------------------------");
    }
    totalrt=totalwt;
    printf("\n\nTOTAL WAITING TIME: %d",totalwt);
    printf("\nTOTAL RESPONSIVE TIME: %d",totalrt);
    printf("\nTOTAL TURNAROUND TIME: %d\n\n",totaltat);
    return 0;
}
