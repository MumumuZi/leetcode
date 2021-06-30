// // 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。在执行上述操作后，找到包含重复字母的最长子串的长度。

// // 注意：字符串长度 和 k 不会超过 104。

// //  

// // 示例 1：

// // 输入：s = "ABAB", k = 2
// // 输出：4
// // 解释：用两个'A'替换为两个'B',反之亦然。
// // 示例 2：

// // 输入：s = "AABABBA", k = 1
// // 输出：4
// // 解释：
// // 将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
// // 子串 "BBBB" 有最长重复字母, 答案为 4。
#include <string>
#include <vector>
#include <tuple>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.empty()) return 0;
        vector<int> letter(26);
        int max_v = k;
        int i = 0;
        int j = 0;
        int max_let = 0;
        for(; i < s.size(); ++i){
            if(i > 0 && s[i] == s[i-1]){
                letter[s[i]-'A']--;
                continue;
            }
            for(; j < s.size(); ++j){
                letter[s[j]-'A']++;
                max_let = max(max_let, letter[s[j]-'A']);
                if(j - i - max_let + 1 > k){
                    letter[s[j]-'A']--;
                    break;
                }
            }
            max_v = max(max_v, j - i);
            // cout << i << "," << j << "," << j - i << " " << max_let << endl;
            letter[s[i]-'A']--;
            if(j == s.size()) break;
        }
        return max_v;
    }
};

int main(){
    cout << Solution().characterReplacement("KKNNSSAAABCDEED", 4) << endl;;
}