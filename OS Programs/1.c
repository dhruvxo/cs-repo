#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
unsigned int N = 0;
pthread_mutex_t mutex;
unsigned int rc;
//prototypes for callback functions

void* PrintEvenNos(void*);
void* PrintOddNos(void*);
int oddsum=0;
int evensum=0;
void main(void)
{
        void *e1=0;
        void *o1=0;
        int sum=0;
    pthread_create(&tid[0],0,&PrintEvenNos,0);
    pthread_create(&tid[1],0,&PrintOddNos,0);
    //sleep(3);

    pthread_join(tid[0],&e1);
    pthread_join(tid[1],&o1);
    sum=*((int *)e1)+*((int*)o1);
    printf("sum of  first N natual numbers is:%d\n",sum);
}

void* PrintEvenNos(void *ptr)
{
     pthread_mutex_lock(&mutex);
     do
     {
         if(N%2 == 0)
         {
            // printf("Even:%d\n",shared_data);
             evensum=evensum+N;
             N++;

         }
         else
         {
             pthread_mutex_unlock(&mutex);//if number is odd, do not print, release mutex
         }
     } while (N <=10);
printf("evensum=%d\n",evensum);
return (void*)&evensum;
}

void* PrintOddNos(void* ptr1)
{
     pthread_mutex_lock(&mutex);
    do
    {
        if(N%2 != 0)
        {
          //  printf("odd:%d\n",shared_data);
            oddsum=oddsum+N;
             N++;

        }
        else
        {
            rc = pthread_mutex_unlock(&mutex);//if number is even, do not print, release mutex
        }
    } while (N <=10);
printf("odd sum=%d\n",oddsum);
return (void*)&oddsum;
}
