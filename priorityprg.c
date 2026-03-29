#include<stdio.h>
#define N 10
struct process
{
	int pid;
	int wt;
	int bt;
	int tat;
	int pri;
};
void swap(struct process *a, struct process *b)
{
	struct process temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sort(struct process p[], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(p[i].pri > p[j].pri)
			{
				swap(&p[i],&p[j]);
			}
		}
	}
}
void fcfs(struct process p[], int n)
{
	int i;
	p[0].wt = 0;
	for(i=1;i<n;i++)
	{
		p[i].wt = p[i-1].wt + p[i-1].bt;
	}
	for(i=0;i<n;i++)
	{
		p[i].tat = p[i].wt+ p[i].bt;
	}
}
void priority_scheduling(struct process p[], int n)
{
	sort(p,n);
	fcfs(p,n);
}
int main()
{
	struct process p[N];
	int i,n;
	float wsum=0, tsum=0;
	printf("Enter no. of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;
	}
	for(i=0;i<n;i++)
	{
		printf("Enter bt of p[%d]: ", p[i].pid);
		scanf("%d",&p[i].bt);
	}
	for(i=0;i<n;i++)
	{
		printf("Enter priority of p[%d]: ", p[i].pid);
		scanf("%d",&p[i].pri);
	}
	priority_scheduling(p,n);
	printf("\npid\tbt\twt\ttat\tpri\n");
	for(i=0;i<n;i++)
	{
printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tat,p[i].pri);
	}
	printf("\n");
	for(i=0;i<n;i++)
	{
		wsum = wsum + p[i].wt;
		tsum = tsum + p[i].tat;
	}
	printf("\nThe avg waiting time is %.3f\n",(wsum/n));
	printf("\nThe avg tat is %.3f\n",(tsum/n));
	printf("\nPriority Scheduling completed\n");
	return 0;
}

