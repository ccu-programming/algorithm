#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMASS 200
#define MAXITEM 50
#define MAXWEIGHT 200000

int main(){
    int mass[MAXMASS];
    int item[MAXITEM];
    char hasSum[MAXWEIGHT+1];
    int numCase, numMass, numItem;
    int counter;
    int i, j;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d %d", &numMass, &numItem);
        for(i = 0; i < numMass; i++){
            scanf("%d", &mass[i]);
        }
        for(i = 0; i < numItem; i++){
            scanf("%d", &item[i]);
        }

        memset(hasSum, 0, sizeof(hasSum));
        hasSum[0] = 1;

        for(i = 0; i < numMass; i++){
            for(j = MAXWEIGHT; j - mass[i] >= 0; j--){
                //這個重量已經被湊出來 或 這個重量扣掉要加的法碼重量可以被湊出來 => 代表這個重量是湊的出來的
                if(hasSum[j] || hasSum[j-mass[i]]){         
                    hasSum[j] = 1;
                }
            }
        }

        counter = 0;
        for(i = 0; i < numItem; i++){
            if(hasSum[item[i]] == 1){
                counter++;
            }
        }

        printf("%d\n", counter);
    }
}