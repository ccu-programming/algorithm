#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCASE 100000

typedef struct {
    int start;
    int end;
    int weight;
}Job;

int lastUnConflictJob(Job *jobs, int index);
int max(int a, int b);
int compare(const void *a, const void *b);

int main(){
    Job jobs[MAXCASE];
    int result[MAXCASE] = {0};
    int numCase, numJob, lastIndex;
    int i, j;
    
    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numJob);
        for(i = 0; i < numJob; i++){
            scanf("%d", &jobs[i].start);
            scanf("%d", &jobs[i].end);
            scanf("%d", &jobs[i].weight);                        
        }

        //Sort
        qsort(jobs, numJob, sizeof(Job), compare);
        
        //Include , Exclude Current Job Reccur
        result[0] = jobs[0].weight;
        for(i = 1; i < numJob; i++){
            int lastIndex = lastUnConflictJob(jobs, i);

            if(lastIndex != -1){
                result[i] = max(jobs[i].weight + result[lastIndex], result[i-1]);
            } else {
                result[i] = max(jobs[i].weight, result[i-1]);
            }
        }

        printf("%d\n", result[numJob-1]);  
    }
}

int lastUnConflictJob(Job *jobs, int index){
    int lowerBound = 0;
    int upperBound = index - 1;
    int middle;

    while(lowerBound <= upperBound){
        middle = (lowerBound + upperBound)/2;
        if(jobs[middle].end <= jobs[index].start){
            if(jobs[middle+1].end <= jobs[index].start){
                lowerBound = middle + 1;
            }
            else{
                return middle;
            }
        }
        else{
            upperBound = middle - 1;
        }
    }
    return -1;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

int compare(const void *a, const void *b){
    Job *A = (Job *)a;
    Job *B = (Job *)b;

    return A->end - B->end;
}