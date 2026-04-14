#include<stdio.h>
#define N 10
#define M 5
int alloc[N][M];
int max[N][M];
int avail[M];
int need[N][M];
int finish[N];
int work[M];
int safe[N];
int n,m;

int issafe()
{
	int i,j,k,cnt=0;
	int found;
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];
	}
	for(i=0;i<n;i++)
	{
		finish[i]=0;
	}
	while(cnt<n)
	{
		found = 0;
		for(i=0;i<n;i++)
		{
			if(finish[i]==0)
			{
				for(j=0;j<m;j++)
				{
					if(need[i][j]>work[j])
					{
						break;
					}
				}
				if(j==m)
				{
					for(k=0;k<m;k++)
					{
						work[k] = work[k] + alloc[i][k];
					}
					safe[cnt]=i;
					cnt++;
					finish[i]= 1;
					found = 1;
				}				
					
			}
		}
		if(found==0)
		{
			return 0;
		}
	}
	printf("\nSafety sequence is: ");
	for(i=0;i<n;i++)
	{
		printf("P%d ",safe[i]+1);
	}
	return 1;
}

int main()
{
	int i,j;
	printf("\nEnter no. of processes: ");
	scanf("%d",&n);
	printf("\nEnter no. of resources: ");
	scanf("%d",&m);
	printf("\nEnter allocation matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
		printf("\n");
	}
	printf("\nMax requirement matrix: \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter available vectors: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	//to calculate need matrix
	//need = max-alloc
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	if(issafe()==1)
	{
		printf("\nThe system is safe and deadlock-free\n");
	}
	else
	{
		printf("\nSystem is not safe, Deadlock may occur\n");
	}
	return 0;
}








