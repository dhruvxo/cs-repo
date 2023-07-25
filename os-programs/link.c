//WAP to implement CP command using link system call

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
    link("a.txt","b.txt");
    return 0;
}