#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXELEMENT 500

int min(int a, int b);

int main(){
    int sum;
    int numElement;
    int elements[MAXELEMENT];
    int dp_DominateSet[MAXELEMENT][2];
    int i;

    while(scanf("%d", &numElement) != EOF && numElement != 0){
        for(i = 0; i < numElement; i++){
            scanf("%d", &elements[i]);
            dp_DominateSet[i][0] = dp_DominateSet[i][1] = INT_MAX; 
        }

        if(numElement == 1){
            printf("%d\n", elements[0]);
            continue;
        }

        dp_DominateSet[0][0] = elements[0];
        dp_DominateSet[0][1] = 0;

        for(i = 1; i < numElement; i++){
            dp_DominateSet[i][0] = min(
                dp_DominateSet[i][0], 
                min(dp_DominateSet[i-1][0], dp_DominateSet[i-1][1]) + elements[i]
            );
            dp_DominateSet[i][1] = dp_DominateSet[i-1][0];

            if(i != numElement-1 && i - 2 >= 0){
                dp_DominateSet[i+1][0] = dp_DominateSet[i-2][0] + elements[i+1];
            }
        }
        printf("%d\n", min(dp_DominateSet[numElement-1][0], dp_DominateSet[numElement-1][1]));
    }
    return 0;
}

int min(int a, int b){
    return (a < b) ? a : b;
}
