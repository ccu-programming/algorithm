#include <stdio.h>
#include <string.h>

#define MAXNUM 500
#define MAXWEIGHT 100000

int max(int a, int b);

typedef struct{
    int weight;
    int value;
}Item;

int main(){
    Item items[MAXNUM];
    int maxValue[MAXWEIGHT];
    int numItem, totalWeight;
    int i, j;
    
    while(scanf("%d %d", &numItem, &totalWeight) != EOF && numItem != 0){
        for(i = 0 ; i < numItem; i++){
            scanf("%d %d", &items[i].weight, &items[i].value);
        }

        memset(maxValue, 0, sizeof(maxValue));

        for(i = 0; i < numItem; i++){
            for(j = totalWeight; j-items[i].weight >= 0; j--){                                  
                maxValue[j] = max(maxValue[j], maxValue[j-items[i].weight]+items[i].value);
                //max(不選自己, 選自己+扣掉自己weight後之前的value)
            }
        }
        printf("%d\n", maxValue[totalWeight]);
    }
}

int max(int a, int b){
    return (a > b)? a : b;
}