#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int remains = 0;
        int size = gas.size();
        int j = 0;
        for(int i = 0; i < size; ++i){
            if(cost[i] > gas[i]){
                continue;
            }
            remains = 0;
            cout << "try " << i << endl;
            for(j = 0; j < size; ++j){
                remains += gas[(j+i)%size] - cost[(j+i)%size];
                cout << "remains " << remains << endl;
                if (remains < 0){
                    break;
                }
            }
            cout << "result " << j << endl;
            if (j == size){
                return i;
            }
            i += j;
        }
        return -1;
    }
};

int main(){
    vector<int> gas{5,1,2,3,4};
    vector<int> cost{4,4,1,5,1};
    int r = Solution().canCompleteCircuit(gas, cost);
    cout << r;
}