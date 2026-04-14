#include<stdio.h>
#define N 10

struct process 
{
	int pid;
	int bt;
	int wt;
	int tat;
};

void Round_Robin(struct process p[], int n, int q)
{
	int i, time=0, completed=0;
	int rem_bt[n];
	for(int i=0;i<n;i++)
	{
		rem_bt[i] = p[i].bt;	
	}
	while(completed<n)
	{
		for(i=0;i<n;i++)
		{
			if(rem_bt[i]>0)
			{
				if(rem_bt[i]>q)
				{
					time = time + q;
					rem_bt[i] = rem_bt[i] - q;
				}
				else
				{
					time = time + rem_bt[i];
					rem_bt[i]=0;
					p[i].tat = time;
					p[i].wt = p[i].tat - p[i].bt;
					completed = completed + 1;
				}
			}
		}
	}


}

int main()
{
	struct process p[N];
	int i,n,q;
	float wsum=0, tsum=0;
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter BT of p[%d]: ",p[i].pid);
		scanf("%d",&p[i].bt);
	}
	printf("\nTime splice (quantum of time): ");
	scanf("%d",&q);
	Round_Robin(p,n,q);
	printf("\nPID\tBT\tWT\tTAT\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		wsum = wsum + p[i].wt;
		tsum = tsum + p[i].tat;
	}
	printf("\nAvg WT of processes is %.3f\n",(wsum/n));
	printf("\nAvg TAT of processes is %.3f\n",(tsum/n));
	printf("\nRound Robin Scheduling Completed\n");
	return 0;
}
