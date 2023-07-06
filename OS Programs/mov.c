//WAP to implement mov command
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    link("a.txt","/root/tt/a.txt");
    unlink("a.txt");
    return 0;
}