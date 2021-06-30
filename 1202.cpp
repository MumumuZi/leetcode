// 1202. 交换字符串中的元素
// 给你一个字符串 s，以及该字符串中的一些「索引对」数组 pairs，其中 pairs[i] = [a, b] 表示字符串中的两个索引（编号从 0 开始）。

// 你可以 任意多次交换 在 pairs 中任意一对索引处的字符。

// 返回在经过若干次交换后，s 可以变成的按字典序最小的字符串。

 

// 示例 1:

// 输入：s = "dcab", pairs = [[0,3],[1,2]]
// 输出："bacd"
// 解释： 
//dacb
// 交换 s[0] 和 s[3], s = "bcad"
// 交换 s[1] 和 s[2], s = "bacd"
// 示例 2：

// 输入：s = "dcab", pairs = [[0,3],[1,2],[0,2]]
// 输出："abcd"
// 解释：
// 交换 s[0] 和 s[3], s = "bcad"
// 交换 s[0] 和 s[2], s = "acbd"
// 交换 s[1] 和 s[2], s = "abcd"
// 示例 3：

// 输入：s = "cba", pairs = [[0,1],[1,2]]
// 输出："abc"
// 解释：
// 交换 s[0] 和 s[1], s = "bca"
// 交换 s[1] 和 s[2], s = "bac"
// 交换 s[0] 和 s[1], s = "abc"
 

// 提示：

// 1 <= s.length <= 10^5
// 0 <= pairs.length <= 10^5
// 0 <= pairs[i][0], pairs[i][1] < s.length
// s 中只含有小写英文字母
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<vector<int>> transfor(s.size());
        for(auto& pair : pairs){
            if(pair[0] > pair[1]){
                transfor[pair[0]].push_back(pair[1]);
            }else if(pair[0] < pair[1]){
                transfor[pair[1]].push_back(pair[0]);
            }
        }
        string r = s;
        int tmp = 0;
        for(int i = 0; i < s.size(); i++){
            int min_a = s[i];
            int min_p = i;
            for(auto& j : transfor[i]){
                cout << i << "->" << j << ", ";
                if(r[j] > s[i]){
                    min_a = min(min_a, int(r[j]));
                    min_p = j;
                }
            }
            tmp = r[min_p];
            r[min_p] = min_a;
            r[i] = tmp;
            // r.insert(r.begin() + min_p, min_a);
            cout << "insert " << min_p <<  "->" << char(min_a) << "," << r << endl;

        }
        return r;
    }
};
// /https://leetcode-cn.com/problems/smallest-string-with-swaps/

int main(){
    vector<vector<int>> pairs{vector<int>{0, 3}, vector<int>{1, 2},vector<int>{0, 2} };
    cout << Solution().smallestStringWithSwaps("dcab", pairs) << endl;
}
//dcab
//dc