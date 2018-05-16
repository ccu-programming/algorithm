#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTH 500

int max(int a, int b);

int main(){
	char first_line[MAXLENGTH];
	char second_line[MAXLENGTH];
	char temp[MAXLENGTH];
	
	int length[MAXLENGTH+1][MAXLENGTH+1];
	int counter = 0;
	int i, j;
	int length_first_line, length_second_line;

	for(i = 0; i < MAXLENGTH+1; i++){
		length[i][0] = 0;
		length[0][i] = 0;
	};
	
	while(fgets(temp, MAXLENGTH, stdin) != NULL){
		if(counter % 2 == 0){
			strcpy(first_line, temp);
			length_first_line = strlen(first_line);

		}
		else{
			strcpy(second_line, temp);
			length_second_line = strlen(second_line);

			for(j = 1; j < length_second_line; j++){
				for(i = 1; i < length_first_line; i++){
					if(second_line[j-1] == first_line[i-1]){
						length[i][j] = length[i-1][j-1] + 1;	
					}
					else{
						if(length[i-1][j] > length[i][j-1]){
							length[i][j] = length[i-1][j];
						}
						else{
							length[i][j] = length[i][j-1];
						}	
					}
				}
			}
			printf("%d\n", length[length_first_line-1][length_second_line-1]);
		}
		counter++;
	}
	
}

int max(int a, int b){
	if(a > b){
		return a;
	}
 	else{
		return b;
	}
}
