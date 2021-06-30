// 在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。

// （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。

// 返回区域的数目。

//  

// 示例 1：

// 输入：
// [
//   " /",
//   "/ "
// ]
// 输出：2
// 解释：2x2 网格如下：

// 示例 2：

// 输入：
// [
//   " /",
//   "  "
// ]
// 输出：1
// 解释：2x2 网格如下：

// 示例 3：

// 输入：
// [
//   "\\/",
//   "/\\"
// ]
// 输出：4
// 解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
// 2x2 网格如下：

// 示例 4：

// 输入：
// [
//   "/\\",
//   "\\/"
// ]
// 输出：5
// 解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
// 2x2 网格如下：

// 示例 5：

// 输入：
// [
//   "//",
//   "/ "
// ]
// 输出：3
// 解释：2x2 网格如下：

//  

// 提示：

// 1 <= grid.length == grid[0].length <= 30
// grid[i][j] 是 '/'、'\'、或 ' '。
#include <vector>
using namespace std;
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        vector<int> leader(grid.size() * 4, -1);
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < m; j++){
                char c = grid[i][j];
                int n = i*m+j;
                int l1 = -1;
                int l2 = -1;
                if(c == '/'){
                    if(j != 0){
                        if(leader[4 * (n-1) + 1] != -1){
                            l1 = leader[4 * (n-1) + 1];
                        }else if(leader[4 * (n-1) + 3] != -1){
                            l1 = leader[4 * (n-1) + 3];
                        }
                    }else{
                        leader[4 * n] = 4 * n;
                        leader[4 * n + 3] = 4 * n + 3;
                        continue;
                    }
                    if( i != 0){
                        
                    }
                }
            }
        }
    }
};