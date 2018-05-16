#include <stdio.h>
#include <stdlib.h>
#define MAXBOX 1000

int compare(const void *a, const void *b);

int main(){
    int deliverBoxTime[MAXBOX];
    int numCase, numBox;
    int deliverTime, previousWaitTime, waitTime;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numBox);
        for(i = 0; i < numBox; i++){
            scanf("%d", &deliverBoxTime[i]);
        }

        qsort(deliverBoxTime, numBox, sizeof(int), compare);

        deliverTime = previousWaitTime = deliverBoxTime[0];
        for(i = 1; i < numBox; i++){
            waitTime = previousWaitTime + deliverBoxTime[i-1] + deliverBoxTime[i];
            deliverTime += waitTime;
            previousWaitTime = waitTime;
        }

        printf("%d\n", deliverTime);
    }
}

int compare(const void *a, const void *b){
    int *A = (int *)a;
    int *B = (int *)b;

    return *A - *B;
}