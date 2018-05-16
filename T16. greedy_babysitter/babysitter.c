#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCANDIDATE 50
#define TEMPLENGTH 32

typedef struct{
    int start;
    int end;
}Candidate;

void selectBabySitter(Candidate *candidates, int counter);
int compare(const void *a, const void *b);

int main(){
    Candidate candidates[MAXCANDIDATE];
    char temp[TEMPLENGTH];
    int numCase;
    int tempNum1, tempNum2;
    int i, counter = 0;

    fgets(temp, TEMPLENGTH, stdin);
    sscanf(temp, "%d", &numCase);
    getchar();
    while(numCase--){
        counter = 0;
        while(fgets(temp, TEMPLENGTH, stdin) != NULL && strcmp(temp, "\n") != 0){
            if(sscanf(temp, "%d %d", &tempNum1, &tempNum2) == 2){
                candidates[counter].start = tempNum1;
                candidates[counter].end = tempNum2;
                if(candidates[counter].start > candidates[counter].end){
                    int tmp = candidates[counter].start;
                    candidates[counter].start = candidates[counter].end;
                    candidates[counter].end = tmp;
                }
                counter++;
            }
        }
        qsort(candidates, counter, sizeof(Candidate), compare);
        selectBabySitter(candidates, counter);
    }
}

void selectBabySitter(Candidate *candidates, int counter){
    int previousSelectIndex;
    int currentSelectIndex;
    int selectCandidate = 1;
    int i;

    previousSelectIndex = currentSelectIndex = 0;
    for(i = 1; i < counter; i++){
        if(candidates[i].start > candidates[previousSelectIndex].end + 1){
            previousSelectIndex = currentSelectIndex;
            i = currentSelectIndex;
            selectCandidate++;
        }
        else{                       
            if(candidates[i].end > candidates[currentSelectIndex].end){
                if(candidates[i].end < 199){
                    currentSelectIndex = i;
                }
                else{
                    selectCandidate++;
                    break;                        
                }
            }
        }
    }
    printf("%d\n", selectCandidate);
}

int compare(const void *a, const void *b){
    Candidate *A = (Candidate *)a;
    Candidate *B = (Candidate *)b;

    if(A->start == B->start){
        return B->end - A->end;
    }
    else{
        return A->start - B->start;
    }
}