#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 50000

typedef struct{
    int start;
    int end;
}Line;

int compare(const void *a, const void *b);

int main(){
    Line lines[MAXLINE];
    long long coverLength;
    int endPointPosition;
    int numCase, numLine;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numLine);
        for(i = 0; i < numLine; i++){
            scanf("%d %d", &lines[i].start, &lines[i].end);
        }
        
        qsort(lines, numLine, sizeof(Line), compare);

        coverLength = lines[0].end - lines[0].start;
        endPointPosition = lines[0].end;
        for(i = 1; i < numLine; i++){
            if(lines[i].start >= endPointPosition){
                coverLength += lines[i].end - lines[i].start;
                endPointPosition = lines[i].end;
            }
            else if(lines[i].end >= endPointPosition){
                coverLength += lines[i].end - endPointPosition;
                endPointPosition = lines[i].end;
            }
        }

        printf("%lld\n", coverLength);
    }
}

int compare(const void *a, const void *b){
    Line *A = (Line *)a;
    Line *B = (Line *)b;

    return A->start - B->start;
}