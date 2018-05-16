#include <cstdio>
#include <queue>

using namespace std;

int main(){
    priority_queue <int, vector<int>, greater<int>> symbols;
    long long totalBit;
    int numCase, numSymbol, element;
    int i;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d", &numSymbol);
        for(i = 0; i < numSymbol; i++){
            scanf("%d", &element);
            symbols.push(element);
        }

        totalBit = 0;
        while(symbols.size() > 1){
            element = 0;

            element += symbols.top();           
            symbols.pop();
            element += symbols.top();          
            symbols.pop();
            symbols.push(element);

            totalBit += element;       
        }
        
        //clear priority_queue
        while(!symbols.empty()){
            symbols.pop();
        }

        printf("%lld\n", totalBit);
    }
    return 0;
}