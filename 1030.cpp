#include <vector>
#include <array>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> history(R, vector<int>(C, 0));
        vector<pair<int, int>> stack;
        stack.emplace_back(r0, c0);
        int stack_top = 0;
        vector<vector<int>> results{vector<int>{r0, c0}};
        int r, c;
        while(stack.size() != stack_top){
            r = stack[stack_top].first;
            c = stack[stack_top].second;
            if(r != 0 && history[r-1][c] == 0){
                results.push_back({r-1, c});
                history[r-1][c] = 1;
                stack.emplace_back(r-1, c);
            }
            if(r != R-1 && history[r+1][c] == 0){
                results.push_back({r+1, c});
                history[r+1][c] = 1;
                stack.emplace_back(r+1, c);
            }
            if(c != 0 && history[r][c-1] == 0){
                results.push_back({r, c-1});
                history[r][c-1] = 1;
                stack.emplace_back(r, c-1);
            }
            if(c != C-1 && history[r][c+1] == 0){
                results.push_back({r, c+1});
                history[r][c+1] = 1;
                stack.emplace_back(r, c+1);
            }
            ++stack_top;
            history[r][c] = 1;
        }
        return results;
    }
};

int main(){
    vector<vector<int>> results = Solution().allCellsDistOrder(2, 3, 1, 2);
    for(auto& i : results){
        cout << i[0] << " " << i[1] << endl;
    }
}