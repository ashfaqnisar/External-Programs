#include <stdio.h>// fifo

int number,data[50],p[50],hit,frames;
int faultCount;
int i,j,k;

void getData() {
    printf("Enter the no of pages required");
    scanf("%d", &number);

    printf("\nEnter the data for the pages:\n");
    for (int i = 0; i < number; ++i) {
        scanf("%d",&data[i]);
    }

    printf("\nEnter the no of frames required:\n");
    scanf("%d",&frames);
}

void intialize(){
    faultCount = 0;
    for (i = 0; i < frames ; ++i) {
        p[i]=9999;
    }
}

int isHit(int p_data){
    hit=0;
    for ( j = 0; j < frames ; ++j) {
        if(p[j] == p_data){
           hit =1;
           break;
        }
    }
    return hit;
}
void dispPages(){
    for (k = 0; k < frames; ++k) {
        if(p[k] != 9999){
            printf(" 5%d",p[k]);
        }
    }
}
void dispFaultCount(){
    printf("\nTotal no of faults are: %d",faultCount);
}

int main(){

    getData();
    intialize();

    for ( i = 0; i < number; ++i) {
        printf("\nFor %d: ",data[i]);

        if(isHit(data[i])==0){
            for ( k = 0; k < frames-1 ; ++k) {
                p[k] = p[k+1];
            }
            p[k]= data[i];
            faultCount++;
            dispPages();

        }

        else{
           printf("No Page Fault");
        }
    }
    dispFaultCount();

    return 0;
}