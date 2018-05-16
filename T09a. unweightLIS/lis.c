#include <stdio.h>
#include <stdlib.h>
#define MAXLENGTH 150000

int ceilIndex(int *tailTable, int left, int right, int key);

int main(){
    int sequence[MAXLENGTH];
    int tailTable[MAXLENGTH];
    int numCase, numSequence;
    int length;
    int i, j;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numSequence);
        for(i = 0; i < numSequence; i++){
            scanf("%d", &sequence[i]);
            tailTable[i] = -1;
        }

        tailTable[0] = sequence[0];
        length = 1;
        for(i = 0; i < numSequence; i++){
            if(sequence[i] > tailTable[length - 1]){
                tailTable[length] = sequence[i];
                length++;
            }
            else{
                tailTable[ceilIndex(tailTable, -1, length-1, sequence[i])] = sequence[i];
            }
        }
        printf("%d\n", length);
    }
}

int ceilIndex(int *tailTable, int left, int right, int key){
    while(right - left > 1){
        int index = left + (right-left)/2;

        if(tailTable[index] >= key){
            right = index; //key所在的位置比目前所在index小 往左找
        }else if(tailTable[index] < key){
            left = index;  //key所在的位置比目前所在index大 往右找
        }
    }
    return right;
}