#include <stdio.h>

int i,j,x,number;
int t[20],b[20],sb[20],c[20][20],s[20];

int main(){

    printf("Enter the no of files");
    scanf("%d",&number);

    for ( i = 0; i < number; ++i) {
        printf("Enter the no of blocks occupied by P[%d]",i+1);
        scanf("%d", &b[i]);

        printf("Enter the starting block");
        scanf("%d", &sb[i]);

        printf("Enter the size of the file");
        scanf("%d", &s[i]);

        printf("Enter blocks of the file: %d",i+1);
        for (j = 0; j < b[i]; ++j) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nFilename Length StartingBlock");

    for (i = 0; i < number; ++i) {
        printf("\n%d %d %d", i + 1, b[i], sb[i]);
    }

    printf("\nEnter the filename:");
    scanf("%d", &x);
    for (int i = 0; i < number; ++i) {
        printf("\nIndex is %d", sb[i]);
        printf("\nBlocks Occupied:");
        for (j = 0; j < b[i] ; ++j) {
            printf(" %d",c[i][j]);
        }
    }


    return 0;
}