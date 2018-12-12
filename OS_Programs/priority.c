#include <stdio.h>//Priority

int i,j,number, positon, temp;
int burstTime[100], turnAroundTime[100], waitingTime[100], process[100], priority[100];
int avgWaitTime, avgTurnAroundTime;

int main() {


    printf("Please, Enter the Number of process: ");
    scanf("%d",&number);

    printf("Please, Enter the Burst Time And Priority for all the process \n");
    for (i = 1; i <= number; ++i) {
        printf("Burst Time for the %d process: \t\n",i);
        scanf("%d",&burstTime[i-1]);

        printf("Priority for the %d process: \n",i);
        scanf("%d", &priority[i-1]);
    }

    for (i = 0; i < number; ++i) {
        positon = i;

        for (j = i+1; j < number ; ++j) {

            if(priority[j]<priority[positon]){
                positon = j;
            }
        }

        temp = priority[i];
        priority[i] = priority[positon];
        priority[positon] = temp;

        temp = burstTime[i];
        burstTime[i] = burstTime[positon];
        burstTime[positon] = temp;

        temp = process[i];
        process[i] = process[positon];
        process[positon] = temp;

    }

    printf("Calculating the Waiting Time for the process\n");
    waitingTime[0]=0;
    for (i = 1; i <= number ; ++i) {
        waitingTime[i]=burstTime[i-1] + waitingTime[i-1];
    }

    printf("Calculating the Turn Around Time\n\n");
    for ( i = 1; i <= number ; ++i) {
        turnAroundTime[i-1] = burstTime[i-1] + waitingTime[i-1];
    }

    printf("Priority Process:\n");

    for ( i = 1; i <= number; ++i) {
        avgWaitTime = avgWaitTime + waitingTime[i-1];
        avgTurnAroundTime = avgTurnAroundTime + turnAroundTime[i-1];

        printf("The Burst Time for the %d process is: %d \n",i,burstTime[i-1]);
        printf("The Waiting Time for the %d process is %d\n",i, waitingTime[i-1]);
        printf("The Turn Around Time for the %d process is %d\n",i,turnAroundTime[i-1]);
        printf("The Priority for the %d process is %d \n\n",i,priority[i-1]);
    }

    printf("The Average Waiting Time is:  %d\n", avgWaitTime/number);
    printf("The Average Turn Around Time is:  %d\n", avgTurnAroundTime/number);

    return 0;
}