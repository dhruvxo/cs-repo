#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

void *lower();
void *upper();

sem_t chk1,chk2;//,sm;
pthread_mutex_t sm; 
int main()
{
	pthread_t ptid,ctid;
	
	sem_init(&chk1, 1, 1);
	sem_init(&chk2, 1, 0);
	//sem_init(&sm, 1, 1);	
       if (pthread_mutex_init(&sm, NULL) != 0) { 
        printf("\n mutex init has failed\n"); 
        return 1; 
    }
	pthread_create(&ptid,NULL,lower,NULL);
	pthread_create(&ctid,NULL,upper,NULL);
	
	pthread_join(ptid,NULL); 
	pthread_join(ctid,NULL);
	printf("\n");
}

void *lower()
{
	int i = 0; 
	while(i < 26)
	{
		sem_wait(&chk1);
		//sem_wait(&sm);
                 pthread_mutex_lock(&sm);
		printf("%c",(97+i));
		pthread_mutex_unlock(&sm);
		sem_post(&chk2);
		++i;
	}
}

void *upper()
{
	int i=0;
	while(i < 26)
	{
		sem_wait(&chk2);
		//sem_wait(&sm);
		pthread_mutex_lock(&sm);
		printf("%c",(65+i));
		pthread_mutex_unlock(&sm);
		//sem_post(&sm);
		sem_post(&chk1);
		++i;	
	}
}

