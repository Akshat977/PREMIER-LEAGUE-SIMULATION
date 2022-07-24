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

void result(int id, int teams)
{
int arr[teams+1][6];
int* a=(int*)shmat(id,NULL,0);

//STORING THE RESULTS AS A MATRIX
for(int i=1;i<=teams;i++)
{
    arr[i][0]=i;
    for(int j=1;j<6;j++)
    {
        arr[i][j]=a[(10000*i)+j];
    }
}



//SORTING THE MATRIX:
for(int i=1;i<=teams;i++)
{

    for(int j=i+1;j<=teams;j++)
{
if(arr[i][5]<arr[j][5])//points of latter are more
{
    for (int k=0; k<6; ++k){
  int temp;
  temp = arr[j][k];
  arr[j][k] = arr[i][k];
  arr[i][k] = temp;
}
}
else if(arr[i][5]==arr[j][5])
{
    if(arr[i][4]<arr[j][4])//goals of latter more
    {
       for (int k=0; k<6; ++k){
  int temp;
  temp = arr[j][k];
  arr[j][k] = arr[i][k];
  arr[i][k] = temp;
}
    }
    else//lower index first
        continue;
}
else
    continue;
}
}

//DISPLAYING THE FINAL TABLE:
printf("\nTeam\tW\tD\tL\tGS\tPoints\n");
printf("------------------------------------------------\n");
for(int i=1;i<=teams;i++)
{
    for(int j=0;j<6;j++)
    {
        printf("%d\t",arr[i][j]);
    }
    printf("\n");
}
}
