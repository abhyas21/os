#include<stdio.h>
#define N 10
struct process{
	int pid;
	int bt;
	int wt;
	int tat;
};
void fcfs(struct process p[],int n)
{
	int i=0;
	p[0].wt=0;
	for(i=1;i<n;i++)
	{
		p[i].wt = p[i-1].wt + p[i-1].bt;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat = p[i].wt + p[i].bt;
	}
	printf("\npid\tbt\twt\ttat\n");
	printf("\n---------------------------------------\n");
	for(i=0;i<n;i++)
	{
printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat);
	}
}

int  main()
{
	struct process p[N];
	int i,n;
	float wsum=0,tsum=0;
	printf("Enter no. of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter bt of process %d: ", p[i].pid);
		scanf("%d",&p[i].bt);
	}
	fcfs(p,n);
	for(i=0;i<n;i++)
	{
		wsum = wsum + p[i].wt;
		tsum = tsum + p[i].tat;
	}
	printf("The average waiting time of processes is %.3f\n",(wsum/n));
	printf("The average turnaround time of processes is %.3f\n",(tsum/n));
	printf("fcfs completed\n");
}
