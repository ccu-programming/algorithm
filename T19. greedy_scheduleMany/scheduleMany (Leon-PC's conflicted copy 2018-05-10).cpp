#include <cstdio>
#include <queue>
#define MAXJOB      100000
#define MAXMACHINE  10000

using namespace std;
int main(){
    priority_queue <int, vector<int>, greater<int> > machines;
    int jobs[MAXJOB];
    int numCase, numJob, numMachine;
    int completeTime;
    int machineTime;
    int i, j;

    scanf("%d", &numCase);
    while(numCase--){
        scanf("%d %d", &numJob, &numMachine);
        for(i = 0; i < numJob; i++){
            scanf("%d", &jobs[i]);
        }

        while(!machines.empty()){
            machines.pop();
        }
        for(i = 0; i < numMachine; i++){
            machines.push(0);
        }

        for(i = 0; i < numJob; i++){
            machineTime = machines.top() + jobs[i];
            machines.pop();
            machines.push(machineTime);
        }

        //找機器花最多時間的那台 （最後一台）
        while(machines.size() != 1){
            machines.pop();            
        }
        completeTime = machines.top();
        
        printf("%d\n", completeTime);
    }
}