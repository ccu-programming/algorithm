#include <stdio.h>
#include <string.h>

#define MAXNUM 500
#define MAXWEIGHT 100000

int max(int a, int b);

int main(){
    int num, weight;
    int Price[MAXNUM] = {0};
    int Weight[MAXNUM] = {0};
    int Value[MAXWEIGHT] = {0};    
    int i, j;

    while(scanf("%d %d", &num, &weight) != EOF && num != 0){
        for(i = 0; i < num; i++){
            scanf("%d %d", &Weight[i], &Price[i]);
        }
    
        memset(Value, 0, sizeof(Value));

        for(i = 0; i < num; i++){
            for(j = weight; j - Weight[i] >= 0; --j){
                Value[j] = max(Value[j], (Value[j - Weight[i]] + Price[i]));
            }
        }
        printf("%d\n", Value[weight]);    
    }
    return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
}