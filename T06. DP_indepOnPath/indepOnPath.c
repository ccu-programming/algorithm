#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXELEMENT 500

int max(int a, int b);

int main(){
    int numElement;
    int elements[MAXELEMENT];
    int maxSubsetWeight[MAXELEMENT+1];
    int i, j;

    while(scanf("%d", &numElement) != EOF && numElement != 0){
        for(i = 0; i < numElement; i++){
            scanf("%d", &elements[i]);
        }

        memset(maxSubsetWeight, 0, sizeof(maxSubsetWeight));        //A[0] = 0, A[1] = Element_1;
        maxSubsetWeight[1] = elements[0];

        for(i = 2; i <= numElement; i++){
            maxSubsetWeight[i] = max(maxSubsetWeight[i-1], (maxSubsetWeight[i-2] + elements[i-1]));
        }
        printf("%d\n", maxSubsetWeight[numElement]);
    }
    return 0;
}

int max(int a, int b){
    return (a > b) ? a : b;
}