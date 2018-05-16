#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMASS 200
#define MAXITEM 50
#define MAXWEIGHT 200000

int main(){
    int testCase;
    int mass, item;
    int massArr[MAXMASS];
    int itemArr[MAXITEM];
    char hasSum[MAXWEIGHT+1];
    int i, j;
    int counter;

    scanf("%d", &testCase);
    while(testCase--){
        scanf("%d %d", &mass, &item);
        for(i = 0; i < mass; i++){
            scanf("%d", &massArr[i]);
        }
        for(i = 0; i < item; i++){
            scanf("%d", &itemArr[i]);
        }

        memset(hasSum, 0, sizeof(hasSum));     //[T, F, F, F, F, ...]
        hasSum[0] = 1;

        for(i = 0; i < mass; i++){
            for(j = MAXWEIGHT; j - massArr[i] >= 0; j--){
                if(hasSum[j] || hasSum[(j-massArr[i])]){
                    hasSum[j] = 1;
                }
            }
        }

        counter = 0;
        for(i = 0; i < item; i++){
            if(hasSum[itemArr[i]] == 1){
                counter++;
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}