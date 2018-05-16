#include <cstdio>
#include <vector>
#define MAXLENGTH 150000

using namespace std;

int main(){
    vector<int> tailTable;    
    int sequence[MAXLENGTH];
    int numCase, numSequence;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numSequence);
        for(i = 0; i < numSequence; i++){
            scanf("%d", &sequence[i]);
        }

        tailTable.clear();
        tailTable.push_back(sequence[0]);

        for(i = 1; i < numSequence; i++){
            if(sequence[i] > tailTable.back()){
                tailTable.push_back(sequence[i]);
            }
            else{
                *lower_bound(tailTable.begin(), tailTable.end(), sequence[i]) = sequence[i];
            }
        }

        printf("%d\n", tailTable.size());
    }
}