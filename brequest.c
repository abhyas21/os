#include<stdio.h>
#define N 10
#define M 5
int alloc[N][M];
int max[N][M];
int avail[M];
int need[N][M];
int finish[N];
int work[M];
int safe[M];
int request[M];
int n,m;
int issafe()
{
	int i,j,k,found;
	int cnt=0;
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
					safe[cnt] = i;
					cnt++;
					finish[i]=1;
					found=1;
				}
			}
		}
		if(found == 0)
		{
			return 0;
		}
	}
	printf("\nSafety sequence is: ");
	for(i=0;i<n;i++)
	{
		printf("P%d ",safe[i]);
	}
	return 1;
}

int main()
{
	int i,j,pid;
	printf("\nEnter the no. of processes: ");
	scanf("%d",&n);
	printf("\nEnter the no. of resources: ");
	scanf("%d",&m);
	printf("\nEnter allocation matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&alloc[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter max requirement matrix:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
		printf("\n");
	}
	printf("\nEnter available matrix:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
	}
	//need matrix
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}

	}
	printf("\nEnter pid of the requesting process: ");
	scanf("%d",&pid);
	printf("\nEnter request matrix:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&request[i]);
	}
	for(i=0;i<m;i++)
	{
		if(request[i]>need[pid][i])
		{
			printf("\nRequest is exceeding its maximum");
			return 0;
		}
	}
	for(i=0;i<m;i++)
	{
		if(request[i]>avail[i])
		{
			printf("\nResource is not available");
			return 0;
		}
	}
	for(i=0;i<m;i++)
	{
		avail[i]= avail[i] - request[i];
		alloc[pid][i] = alloc[pid][i] + request[i];
		need[pid][i] = need[pid][i] - request[i];
	}
	if(issafe()==1)
	{
		printf("\nRequest is granted");
	}
	else
	{
		printf("\nRequest is denied");
	}
	for(i=0;i<m;i++)
	{
		avail[i] = avail[i] + request[i];
		alloc[pid][i] = alloc[pid][i] - request[i];
		need[pid][i] = need[pid][i] + request[i];
	}
	return 0;
}














