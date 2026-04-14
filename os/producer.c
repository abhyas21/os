#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/sem.h>

#define N 5

typedef struct
{
	int in;
	int out;
	int buf[N];
} shared_data;

void sem_wait(int semid, int semnum)
{
	struct sembuf bf = {semnum, -1, 0};
	semop(semid, &bf, 1);
}

void sem_signal(int semid, int semnum)
{
	struct sembuf bf = {semnum, +1, 0};
	semop(semid, &bf, 1);
}

int main()
{
	key_t key;
	int shmid;
	int semid;
	int i;
	shared_data *data;
	key = ftok("shmfile",55);
	shmid = shmget(key,sizeof(shared_data),0666|IPC_CREAT);
	data = (shared_data*)shmat(shmid,NULL,0);
	semid = semget(key, 3, 0666|IPC_CREAT);
	semctl(semid, 0, SETVAL, 1);
	semctl(semid, 1, SETVAL, N);
	semctl(semid, 2, SETVAL, 0);
	data->in = 0;
	data->out = 0;
	for(i=1;i<=10;i++)
	{
		sem_wait(semid, 1);
		sem_wait(semid, 0);
		data->buf[data->in] = i;
		printf("Producer produced an item %d and placed at %d\n",i,data->in);
		data->in = (data->in+1)%N;
		sem_signal(semid, 0);
		sem_signal(semid, 2);
		sleep(2);
	}
	shmdt(data);
	return 0;
}



















