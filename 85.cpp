#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int max_rect(vector<vector<char>>& matrix, size_t& s_row, size_t& s_col, size_t& rows, size_t& cols ){
        size_t max_row = rows-1;
        size_t max_col = cols-1;
        int max_score = 0;
        int temp = 0;
        for(size_t i = s_row; i <= max_row; ++i){
            size_t j = s_col;
            for(; j <= max_col; ++j){
                if(matrix[i][j] == '0') break;
            }
            temp = (i - s_row + 1) * (j - s_col);
            if (temp == 0) return max_score;
            if (temp > max_score){
                max_score = temp;
            }
            max_col = j-1;
        }
        return max_score;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        size_t rows = matrix.size();
        if (rows == 0) return 0;
        size_t cols = matrix[0].size();
        if (cols == 0) return 0;
        int max_v = 0;
        int temp = 0;
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    temp = max_rect(matrix, i, j, rows, cols);
                    cout << "max_rect " << i << j << temp << endl;
                    if (max_v < temp){
                        max_v = temp;
                    }
                }
            }
        }
        return max_v;
    }
};
// 1 0 1 1 1
// 0 1 0 1 0
// 1 1 0 1 1
// 1 1 0 1 1
// 0 1 1 1 1

int main(){
    vector<vector<char>> rect ={{'1','0','1','1','1'},{'0','1','0','1','0'},{'1','1','0','1','1'},{'1','1','0','1','1'},{'0','1','1','1','1'}};
    int ret = Solution().maximalRectangle(rect);
    cout << ret << endl;
}