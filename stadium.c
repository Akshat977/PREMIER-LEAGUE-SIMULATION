#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <asm/unistd.h>
#include <time.h>
#include "FOOTBALL.h"

void stadium(int id,  int teams,int* A,int* B, int len)
{

    int* a=(int*)shmat(id,NULL,0);
    srand(time(0));


    int pid_array[teams+1];
    for(int i=1;i<=teams;i++)
    {
        int pid=fork();

        if(pid==0)
        {
            int w=0;
            do
            {
            while( a[getpid()]!=1);
            clock_t t=clock();
            int m,n;
            while(((clock()-t))<=3000)//ENSURING A MATCH RUNS FOR 3 SECONDS
                {
            m=rand()%6;
            n=rand()%6;}
            printf("Starting match: Team %d vs Team %d\n",A[a[1]],B[a[1]]);
            printf("Match ended: Team %d vs Team %d\tResult:%d-%d\n",A[a[1]],B[a[1]],m,n);
if(m>n)
{
    a[10000*A[a[1]]+1]+=1;
    a[10000*A[a[1]]+4]+=m;
    a[10000*A[a[1]]+5]+=3;

    a[10000*B[a[1]]+3]+=1;
    a[10000*B[a[1]]+4]+=n;

}
else if(m==n)
{
    a[10000*A[a[1]]+2]+=1;
    a[10000*A[a[1]]+4]+=m;
    a[10000*A[a[1]]+5]+=1;

    a[10000*B[a[1]]+2]+=1;
    a[10000*B[a[1]]+4]+=n;
    a[10000*B[a[1]]+5]+=1;
}
else
{
    a[10000*B[a[1]]+1]+=1;
    a[10000*B[a[1]]+4]+=n;
    a[10000*B[a[1]]+5]+=3;

    a[10000*A[a[1]]+3]+=1;
    a[10000*A[a[1]]+4]+=m;
}
a[getpid()]=0;
            w+=1;
            }while(w<(teams-1));
            exit(0);
        }
a[pid]=0;
        pid_array[i]=pid;

    }


    for(int i=1;i<len;i+=1)
    {
        a[1]=i;
        a[pid_array[A[i]]]=1;
sleep(4);

        a[pid_array[A[i]]]=0;



    }
while(wait(NULL)!=-1);

}
