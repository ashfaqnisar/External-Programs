#include <stdio.h>
#include <string.h>

char a[20],fs[20]="";

int main(){
    printf("Enter the bit string");
    scanf("%s",a);

    strcat(fs,"01111110");

    if(strlen(a)<5){
        strcat(fs,a);
    }

    else{
        for (int i = 0; i < strlen(a) -4; ++i) {
            for (int j = 0; j < i+5 ; ++j) {

            }

            if(){

            }
            else{

            }
        }


    }

    strcat(fs,"01111110");
}