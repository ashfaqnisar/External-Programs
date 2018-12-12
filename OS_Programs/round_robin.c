#include<stdio.h>//Round Robin

int main()
{

    int i,j,number,time,remain,flag=0,timeQuantum;
    int avgWaitingTime =0,avgTurnAroundTime=0,arrivalTime[10],burstTime[10],remainingTime[10];

    printf("Please Enter the Number of Process:\t ");
    scanf("%d",&number);
    remain=number;

    for(i=0;i<number;i++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :",i+1);
        scanf("%d",&arrivalTime[i]);
        scanf("%d",&burstTime[i]);
        remainingTime[i]=burstTime[i];
    }

    printf("Enter the Time Quantum:\t");
    scanf("%d",&timeQuantum);

    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(time=0,i=0;remain!=0;)
    {
        if(remainingTime[i]<=timeQuantum && remainingTime[i]>0)
        {
            time+=remainingTime[i];
            remainingTime[i]=0;
            flag=1;
        }

        else if(remainingTime[i]>0)
        {
            remainingTime[i] -= timeQuantum;
            time += timeQuantum;
        }

        if(remainingTime[i]==0 && flag==1)
        {
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrivalTime[i],time-arrivalTime[i]-burstTime[i]);

            avgWaitingTime +=time-arrivalTime[i]-burstTime[i];
            avgTurnAroundTime+=time-arrivalTime[i];
            flag=0;
        }

        if(i==number-1) {
            i = 0;
        }

        else if(arrivalTime[i+1]<=time) {
            i++;
        }

        else
            i=0;
    }
    printf("\nAverage Waiting Time= %f\n",avgWaitingTime * 1.0/number);
    printf("Average Turnaround Time = %f",avgTurnAroundTime * 1.0/number);

    return 0;
}