#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXCUT 50+2

int main(){
    int cutPoint[MAXCUT] = {0};
    int dp[MAXCUT][MAXCUT] = {0};
    int length, cutNum, totalPoint;
    int range, left, right, middle;
    int min, cost;
    int i, j;

    while(scanf("%d", &length) != EOF && length != 0){
        scanf("%d", &cutNum);

        for(i = 1; i < cutNum+1; i++){
            scanf("%d", &cutPoint[i]);
        }
        totalPoint = cutNum+2;
        cutPoint[0] = 0;
        cutPoint[totalPoint-1] = length;

        for(range = 2; range < totalPoint; range++){
            for(left = 0; (right = left + range) < totalPoint; left++){
                min = INT_MAX;
                for(middle = left+1; middle < right; middle++){
                    cost = dp[left][middle] + dp[middle][right] + (cutPoint[right] - cutPoint[left]);
                    if(min > cost){
                        min = cost;
                    }
                }
                dp[left][right] = min;
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][totalPoint-1]);
    }

}