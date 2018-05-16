#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 500

int max(int a, int b);

int main(){
    char first[MAXLENGTH]; 
    char second[MAXLENGTH];
    int dp[MAXLENGTH+1][MAXLENGTH+1] = {0};                    //最外圈設為0
    int counter;
    int i, j;

    while(scanf("%s", first) != EOF){
        scanf("%s", second);

        memset(dp, 0, sizeof(dp[0][0]));

        for(i = 1; i <= strlen(second); i++){                   //i -> second, j -> first
            for(j = 1; j <= strlen(first); j++){
                if(second[i-1] == first[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;                //相同 -> 取左上角+1
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);     //不同 -> max(上面, 左邊)
                }
            }
        }

        printf("%d\n", dp[strlen(second)][strlen(first)]);
    }
}

int max(int a, int b){
    return (a > b) ? a : b;
}