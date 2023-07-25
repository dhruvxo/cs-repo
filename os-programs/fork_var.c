#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
void main()
{
        int x = 1;

if (fork() == 0)
{
int y=20;
printf("Child has x = %d\n", ++x);
printf("child has y=%d\n",y);
exit(0);
}
else
{
sleep(3);
wait(NULL);
printf("Parent has x = %d\n", --x);
//printf("Parent has y=%d\n",y);
}
}