#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/ipc.h>
#include<stdlib.h>

#define N 5

typedef struct
{
	int in;
	int out;
	int buf[N];
} shared_data;

void sem_wait(int semid, int semnum)
{
	struct sembuf sb = {semnum, -1, 0};
	semop(semid, &sb, 1);
}

void sem_signal(int semid, int semnum)
{
	struct sembuf sb = {semnum, 1, 0};
	semop(semid,&sb,1);
}

int main()
{
	key_t key;
	int i, item;
	int shmid, semid;
	shared_data *data;
	key = ftok("shmfile",55);
	shmid = shmget(key,sizeof(shared_data),0666);
	data = (shared_data*)shmat(shmid,NULL,0);
	semid = semget(key, 3, 0666);
	/*semctl(semid,0,SETVAL,1);
	semctl(semid,1,SETVAL,N);
	semctl(semid,2,SETVAL,0);
	data->out = 0;*/
	for(i=1;i<=10;i++)
	{
		sem_wait(semid,2);
		sem_wait(semid,0);
		item = data->buf[data->out];
		printf("Consumer consumed %d from %d\n",item, data->out);
		data->out = (data->out+1)%N;
		sem_signal(semid, 0);
		sem_signal(semid, 1);
		sleep(1);
	}
	shmdt(data);
	shmctl(shmid,IPC_RMID, 0);
	semctl(semid,0,IPC_RMID);
	return 0;
}








