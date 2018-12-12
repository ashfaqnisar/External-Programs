#include <stdio.h>

int i,j,n;

int main(){
    printf("Files");
    scanf("%d",n);

    for (i = 0; i < n; ++i) {
        printf("Enter the occcupied blocks:");
        scanf("%d",b[i]);

        printf("StartingBlock");
        scanf("%d", sb[i]);

        for ( j = 0; j < b[i]; ++j) {
            c[i][j] = sb[i]++;
        }
    }
    printf("Filename Length Starting Block")
    for (i = 0; i < n; ++i) {
        printf("%d %d %d",i+1,b[i],sb[i]);

        printf("Enter the filENAME");
        scanf("%d", &x);
        printf("The length is %d",b[x-1]);
        printf("The occupied block is:");

        for ( j = 0; j < b[x-1]; ++j) {
            printf("%d",c[x-1][i]);
        }

    }
}