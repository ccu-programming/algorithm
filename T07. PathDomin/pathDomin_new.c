#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXELEMENT 500

int min(int a, int b);

int main(){
    int sum;
    int numElement;
    int elements[MAXELEMENT];
    int dp_DominateSet[MAXELEMENT+1];
    int i;

    while(scanf("%d", &numElement) != EOF && numElement != 0){
        for(i = 0; i < numElement; i++){
            scanf("%d", &elements[i]);
        }

        if(numElement == 1){
            printf("%d\n", elements[0]);
            continue;
        }

        dp_DominateSet[0] = 0;
        dp_DominateSet[1] = elements[0];

        for(i = 1; i < numElement; i++){
            if(i <= 2){
                //前三個元素 前兩個元素一定要選一個
                dp_DominateSet[i+1] = min(dp_DominateSet[i], dp_DominateSet[i-1]) + elements[i];
            }
            else{
                //選前三個解中的最小解
                dp_DominateSet[i+1] = min(min(dp_DominateSet[i], dp_DominateSet[i-1]), dp_DominateSet[i-2]) + elements[i];
            }
        }
        printf("%d\n", min(dp_DominateSet[numElement-1], dp_DominateSet[numElement]));
    }
    return 0;
}

int min(int a, int b){
    return (a < b) ? a : b;
}
