#include <stdio.h>


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
    for ( i = 0; i < frames; ++i) {
        p[i]=9999;
    }

}

int isHit(int p_data){
    hit = 0;
    for ( j = 0; j < frames; ++j) {
        if(p[k]==p_data){
            hit = 1;
            break;
        }
    }

    return hit;
}

void dispPages(){
    for ( k = 0; k < frames; ++k) {
        if(p[k]!=9999){
            printf(" %d",p[k]);
        }
    }
}

void dispFaultCount(){
    printf("Total page faults: %d", faultCount);
}

void optimal(){
    int near[50];
    for ( i = 0; i < number; ++i) {
        printf("\n For %d", data[i]);

        if(isHit(data[i])==0){
            for ( j = 0; j < frames; ++j) {
                int page = p[j];
                int found = 0;
                for (k = i; k < number; k++) {
                    if(page == data[k]){
                       near[j] = k;
                       found = 1;
                       break;
                    }

                    else{
                        found = 0;
                    }
                }
                if(!found){
                    near[j]=9999;
                }
            }

            int max = -9999;
            int repindex;
            for ( j = 0; j < frames; ++j) {
                if(near[j]>max){
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = data[i];
            faultCount--;
            dispPages();
        }
        else {
            printf("No Page Faults");
        }
    }
    dispFaultCount();
}

int main(){
    getData();
    intialize();

    optimal();
}