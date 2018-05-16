#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCASE 50000

typedef struct {
    int start;
    int end;
}Job;

int compare(const void *a, const void *b);

int main(){
    Job jobs[MAXCASE];
    int numCase, numJob, numSelect;
    int previousEnd;
    int i, j;
    
    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numJob);
        for(i = 0; i < numJob; i++){
            scanf("%d", &jobs[i].start);
            scanf("%d", &jobs[i].end);                       
        }
        qsort(jobs, numJob, sizeof(Job), compare);
        
        numSelect = 1;
        previousEnd = jobs[0].end;
        for(i = 1; i < numJob; i++){
            if(previousEnd <= jobs[i].start){
                previousEnd = jobs[i].end;
                numSelect++;
            }
        }
        printf("%d\n", numSelect);
    }
}

int compare(const void *a, const void *b){
    Job *A = (Job *)a;
    Job *B = (Job *)b;

    return A->end - B->end;
}