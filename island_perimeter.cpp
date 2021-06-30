#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int result = 0;
        int row = grid.size();
        int cloumn = grid[0].size();
        for(size_t i = 0; i < row; ++i){
            for(size_t j = 0; j < cloumn; ++j){
                if((grid[i][j] == 1)){
                    if(j == 0 || (j > 0 && grid[i][j-1] == 0)){
                        result += 1;
                    }
                    if(j == cloumn-1 || (j < cloumn-1 && grid[i][j+1] == 0)){
                        result += 1;
                    }
                    if (i == 0 || (i > 0 && grid[i-1][j] == 0)){
                        result += 1;
                    }
                    if (i == row-1 || (i < row-1 && grid[i+1][j] == 0)){
                        result += 1;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0},
    };
    cout << Solution().islandPerimeter(grid) << endl;
    return 0;
}


// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]
