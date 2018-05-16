#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXCUT 50+2

int main(){
    int point[MAXCUT] = {0};
    int dp[MAXCUT][MAXCUT] = {0};
    int length, num;
    int range, left, right, middle;
    int min, cost;
    int i;

    while(scanf("%d", &length) != EOF && length != 0){
        scanf("%d", &num);
        for(i = 1; i <= num; i++){
            scanf("%d", &point[i]);
        }
        point[0] = 0;
        point[num+1] = length;

        for(range = 2; range <= num + 1; range++){ 
            for(left = 0; (right = left + range) <= num + 1; left++){
                min = INT_MAX;
                for(middle = left + 1; middle < right; middle++){
                    cost = dp[left][middle] + dp[middle][right] + (point[right] - point[left]);
                    if(min > cost){
                        min = cost;
                    }
                }
                dp[left][right] = min;
            }
        }
        printf("The minimum cutting is %d.\n", dp[0][num+1]);
    }
    return 0;
};