#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 	500
#define MATCH 		8
#define MISMATCH 	-5
#define GAP 		-3

int max(int a, int b);

int main(){
	char str[MAXLENGTH], first_str[MAXLENGTH], second_str[MAXLENGTH];

	int length[MAXLENGTH+1][MAXLENGTH+1];
	int first_length, second_length;
	int match, mismatch, gap;
	int i, j;
	int counter = 0;

	for(i = 0; i < MAXLENGTH; i++){
		length[i][0] = GAP * i;
		length[0][i] = GAP * i;
	}

	while(fgets(str, MAXLENGTH, stdin) != NULL){
		if(counter % 2 == 0){
			strcpy(first_str, str);
			first_length = strlen(first_str);
		}
		else{
			strcpy(second_str, str);
			second_length = strlen(second_str);	
			for(j = 1; j < second_length; j++){
				for(i = 1; i < first_length; i++){
					if(second_str[j-1] == first_str[i-1]){
						match = length[i-1][j-1] + MATCH;
						gap = max(length[i-1][j], length[i][j-1]) + GAP;
						length[i][j] = max(match, gap);
					}
					else{
						mismatch = length[i-1][j-1] + MISMATCH;
						gap = max(length[i-1][j], length[i][j-1]) + GAP;
						length[i][j] = max(mismatch, gap);
					}
				}
			}
			printf("%d\n", length[first_length-1][second_length-1]);
		}
		counter++;
	}
	return 0;
}

int max(int a, int b){
	return (a > b)? a : b;
}