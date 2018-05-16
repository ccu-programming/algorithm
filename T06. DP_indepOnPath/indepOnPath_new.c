#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXELEMENT 500

int max(int a, int b);

int main(){
    int elements[MAXELEMENT];
    int maxWeight[MAXELEMENT+1];
    int numElement;
    int i, j;

    while(scanf("%d", &numElement) != EOF && numElement != 0){
        for(i = 0; i < numElement; i++){
            scanf("%d", &elements[i]);
        }

        memset(maxWeight, 0, sizeof(maxWeight));
        maxWeight[1] = elements[0];

        for(i = 2; i < numElement + 1; i++){
            //max(前一個取的總weight, 前一個不取的總weight + 取現在element的weight)
            maxWeight[i] = max(maxWeight[i-1], maxWeight[i-2] + elements[i-1]);
        }

        printf("%d\n", maxWeight[numElement]);
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}