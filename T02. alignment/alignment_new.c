#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH   500
#define MATCH       8
#define MISMATCH    -5
#define GAP         -3

int max(int a, int b, int c);

int main(){
    char first[MAXLENGTH];
    char second[MAXLENGTH];
    int dp[MAXLENGTH+1][MAXLENGTH+1];
    int f_length, s_length;
    int i, j;

    while(scanf("%s", first) != EOF){
        scanf("%s", second);

        f_length = strlen(first);
        s_length = strlen(second);

        for(i = 1; i <= MAXLENGTH; i++){
            dp[i][0] = GAP * i;
            dp[0][i] = GAP * i;
        }

        for(i = 1; i <= s_length; i++){
            for(j = 1; j <= f_length; j++){
                if(first[j-1] == second[i-1]){
                    //相同 ->左上角+match                                  
                    dp[i][j] = dp[i-1][j-1] + MATCH;
                }
                else{
                    //不同 ->max(左上角+mismatch, 上面+gap, 左邊+gap) 
                    dp[i][j] = max(dp[i-1][j-1]+MISMATCH, dp[i-1][j]+GAP, dp[i][j-1]+GAP);
                }
            }
        }
        printf("%d\n", dp[s_length][f_length]);

    }
}

int max(int a, int b, int c){
    if(a > b){
        return (a > c) ? a : c;
    }
    else{
        return (b > c) ? b : c;
    }
}