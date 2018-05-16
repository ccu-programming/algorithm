#include <stdio.h>
#include <stdlib.h>
#define MAXJOB  100
#define TRUE    1
#define FALSE   0

typedef struct {
    int jobTime;
    int deadline;
}Job;

int compare(const void *a, const void *b);

int main(){
    Job jobs[MAXJOB];
    int numCase, numJob;
    int useTime, isCompleteInTime;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numJob);
        for(i = 0; i < numJob; i++){
            scanf("%d", &jobs[i].jobTime);
        }
        for(i = 0; i < numJob; i++){
            scanf("%d", &jobs[i].deadline);
        }

        qsort(jobs, numJob, sizeof(Job), compare);
        
        useTime = 0;
        isCompleteInTime = TRUE;
        for(i = 0; i < numJob; i++){
            useTime += jobs[i].jobTime;
            if(useTime > jobs[i].deadline){
                isCompleteInTime = FALSE;
            }
        }

        if(isCompleteInTime){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}

int compare(const void *a, const void *b){
    Job *A = (Job *)a;
    Job *B = (Job *)b;

    return A->deadline - B->deadline;
}