#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSPY 10005

int main(){
    int chief[MAXSPY];
    int monit[MAXSPY];
    int numCase, numSpy;
    int monitPhone;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        monitPhone = 0;
        memset(monit, 0, sizeof(int)*MAXSPY);
        memset(chief, 0, sizeof(int)*MAXSPY);

        scanf("%d", &numSpy);
        for(i = 1; i < numSpy; i++){
            scanf("%d", &chief[i]);
        }

        for(i = numSpy-1; i > 0; i--){
            if(monit[i] == 0 && monit[chief[i]] == 0){
                monit[chief[i]] = 1;
                monitPhone++;
            }
        }

        printf("%d\n", monitPhone);
    }
}