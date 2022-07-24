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

int main(int argc, char *argv[])
{

    //WRITE IN README: WRITE THE NAME OF THE INPUT FILE(with ".txt") AS COMMAND LINE ARGUMENT OR JUST WRITE input.txt with make command to use the current file.
    if (argc < 1)
        return 0;

    int i,x,key=123,len=0;
    char ch;
    FILE *fptr;
    int length = 0;

    //CONVERETING COMMAND LINE ARGUMENT TO STRING:
    for (i=1; i<argc; i++) {
        length += strlen(argv[i]);
        if (argc > i+1)
            length++;
    }



    char *name;
    name = malloc(length);
    name[0] = '\0';

    for (i=1; i<argc; i++) {
        strcat(name, argv[i]);
        if (argc > i+1)
            strcat(name, " ");
    }

    //READING THE CONTENTS OF THE FILE
    fptr = fopen (name, "r");
	ch = fgetc(fptr);
i=1;
	int c=0,max=0;
int teams=ch-'0';
int A[teams*(teams-1)];
int B[teams*(teams-1)];

	while (ch != EOF)
		{
ch= fgetc(fptr);
		    if(ch>=48 && ch<=57)
		    {
		        if(c==0)
		      {
            A[i]=ch-'0';
		      c=!c;
		      }
		      else
                {
                    B[i]=ch-'0';
		      c=!c;
		      i+=1;
		      }
		      if((ch-'0')>max)
                max=ch-'0';

		    }

		}
    printf("\n");
    fclose (fptr);
    //CREATING SHARED MEMORY:

int id=shmget(key,sizeof(int)*10000*(teams+1),IPC_CREAT|0666);
if(id<=-1)
perror("failed to create\n");
int* a=(int*)shmat(id,NULL,0);


    //INITIALISING POINTS, GOALS, WINS, LOSSES, DRAWS, ETC.
    for(int j=1;j<=teams;j++)
    {
        a[10000*j]=0;//Team
        a[10000*j+1]=0;//wins
        a[10000*j+2]=0;//draws
        a[10000*j+3]=0;//losses
        a[10000*j+4]=0;//goals
        a[10000*j+5]=0;//points
    }

    //PLAYING OUT THE MATCHES
stadium(id,teams,A,B,i);

//DISPLAYING THE RANKINGS
result(id,teams);

    int w=shmdt(a);
    int s=shmctl(id,IPC_RMID,NULL);
      if(s==0)
                printf("\n\nsuccessful delete of the created shared memory\n");
return 0;
}

