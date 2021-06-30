// 有一个二维矩阵 A 其中每个元素的值为 0 或 1 。

// 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。

// 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。

// 返回尽可能高的分数。

//  

// 示例：

// 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// 输出：39
// 解释：
// 转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
// 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
//1 1 1 1  
//1 0 0 1
//1 1 1 1
//

// 提示：

// 1 <= A.length <= 20
// 1 <= A[0].length <= 20
// A[i][j] 是 0 或 1
#include <vector>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

class Solution {
public:
    inline void flip(vector<vector<int>>& A, int row, int cloumn){
        cout << "flip " << row << " " << cloumn << endl;
        if (row != -1){
            for(int i = 0; i < A[0].size(); ++i){
                A[row][i] = 1 - A[row][i];
            }
        }else{
            for(int i = 0; i < A.size(); ++i){
                A[i][cloumn] = 1 - A[i][cloumn];
            }
        }
    }
    int matrixScore(vector<vector<int>>& A) {
        int rows = A.size();
        int cloums = A[0].size();
        int score = 0;
        for(int i = 0; i < cloums; ++i){
            if(i == 0){
                for(int j = 0; j < rows; ++j){
                    if(A[j][0] == 0){
                        flip(A, j, -1);
                    }
                    score += pow(2, cloums-1);
                    cout << i << " " << score << endl;
                }
            }else{
                int need_flip = 0;
                for(int j = 0; j < rows; ++j){
                    cout << "loop: " << i << " " << j <<A[j][i] << endl;
                    if(A[j][i] == 0){
                        ++need_flip;
                    }
                }
                if (need_flip > rows/2){
                    flip(A, -1, i);
                }
                score += max(need_flip, rows-need_flip) * pow(2, cloums-1-i);
                cout << i << " " << score << " " << max(need_flip, rows-need_flip)  << endl;
            }
        }
        return score;
    }
};

int main(){
    //[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
    vector<vector<int>> data{vector<int>{1,1}, vector<int>{0,0}, vector<int>{1,0},vector<int>{1,0}, vector<int>{1,1}};
    cout << Solution().matrixScore(data) << endl;
}

// [[1,1],
// [1,1],
// [1,0],
// [1,0],
// [1,1]]

//[[1,1],
// [0,0],
// [1,0],
// [1,0],
// [1,1]]