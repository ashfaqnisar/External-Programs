#include <stdio.h>
#include <conio.h>

int i,j,number,x;
int b[20], sb[20],t[20],c[20][20];
int main(){


    printf("Please, Enter the no of files");
    scanf("%d",&number);

    for ( i = 0; i < number; ++i) {
        printf("Enter the no of blocks occupied by file[%d]:\n", i+1);
        scanf("%d", &b[i]);

        printf("Enter the starting block for the file[%d]:\n",i+1);
        scanf("%d",&sb[i]);

        t[i] = sb[i];
        for (j = 0; j < b[i] ; ++j) {
            c[i][j] = sb[i]++;
        }

    }
    printf("Filename | Length | Starting Block\n ");

    for (i = 0; i < number; ++i) {
        printf("\nP[%d] | %d | %d ",i+1, b[i], t[i]);

        printf("\nEnter the filename\n");
        scanf("%d",&x);

        printf("Length is: %d\n",b[x-1]);

        printf("BLocks Occcupied:\n");

        for (i = 0; i < b[x-1]; ++i) {
            printf("%d", c[x-1][i]);
        }
    }
}