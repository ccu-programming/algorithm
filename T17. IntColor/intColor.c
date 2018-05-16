#include <stdio.h>
#include <stdlib.h>
#define MAXINTERVAL 50000

typedef struct{
    int start;
    int end;
}Interval;

int compare(const void *a, const void *b);

int main(){
    Interval intervals[MAXINTERVAL];
    int numCase, numInterval;
    int numColor;
    int minColorNeed;
    int rightPoint;
    int i, j;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numInterval);
        for(i = 0; i < numInterval; i++){
            scanf("%d", &intervals[i].start);
            scanf("%d", &intervals[i].end);
        }

        qsort(intervals, numInterval, sizeof(Interval), compare);

        minColorNeed = 0;
        numColor = 1;
        for(i = 0; i < numInterval; i++){
            numColor = i+1;
            for(j = 0; j < i; j++){
                if(intervals[j].end < intervals[i].start){
                    numColor--;
                }
            }
            if(minColorNeed < numColor){
                minColorNeed = numColor;
            }
        }
        printf("%d\n", minColorNeed);
    }
}

int compare(const void *a, const void *b){
    Interval *A = (Interval *)a;
    Interval *B = (Interval *)b;

    return A->start - B->start;
}