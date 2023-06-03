#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t chopstick[5];

void * philosopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,philosopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * philosopher(void * num)
{
	int i=*(int *)num;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room",i);
	sem_wait(&chopstick[i]);
	sem_wait(&chopstick[(i+1)%5]);

	eat(i);
	
	printf("\nPhilosopher %d has finished eating",i);

	sem_post(&chopstick[(i+1)%5]);
	sem_post(&chopstick[i]);
	sem_post(&room);
}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating",phil);
}
