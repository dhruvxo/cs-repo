#include<unistd.h>
#include<dirent.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    struct dirent *dp;
    DIR *dirp;
    char ptr[100];
    struct stat buf; 
    if(argc<2)
    {
        getcwd(ptr,100);
        printf("%s\n",ptr);
        dirp=opendir(ptr);
    }
    else
    dirp=opendir(argv[1]);
    while((dp=readdir(dirp))!=NULL)
    {
        if((strcmp(dp->d_name,".")==0)&(strcmp(dp->d_name,"..")==0))
        continue;
        else
        printf("%s\n",dp->d_name);
        chdir(argv[1]);
        int st=stat(dp->d_name,&buf);
        if(st<0)
        {
            printf("st error\n");exit(1);
        }
        printf("%ld\n",buf.st_size);
        if(buf.st_size<10)
        {
            unlink(dp->d_name);
        }
    }
    return 0;
}