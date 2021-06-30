// 给定一个数字字符串 S，比如 S = "123456579"，我们可以将它分成斐波那契式的序列 [123, 456, 579]。

// 形式上，斐波那契式序列是一个非负整数列表 F，且满足：

// 0 <= F[i] <= 2^31 - 1，（也就是说，每个整数都符合 32 位有符号整数类型）；
// F.length >= 3；
// 对于所有的0 <= i < F.length - 2，都有 F[i] + F[i+1] = F[i+2] 成立。
// 另外，请注意，将字符串拆分成小块时，每个块的数字一定不要以零开头，除非这个块是数字 0 本身。

// 返回从 S 拆分出来的任意一组斐波那契式的序列块，如果不能拆分则返回 []。

//  

// 示例 1：

// 输入："123456579"
// 输出：[123,456,579]
// 示例 2：

// 输入: "11235813"
// 输出: [1,1,2,3,5,8,13]
// 示例 3：

// 输入: "112358130"
// 输出: []
// 解释: 这项任务无法完成。
// 示例 4：

// 输入："0123"
// 输出：[]
// 解释：每个块的数字不能以零开头，因此 "01"，"2"，"3" 不是有效答案。
// 示例 5：

// 输入: "1101111"
// 输出: [110, 1, 111]
// 解释: 输出 [11,0,11,11] 也同样被接受。
//  

// 提示：

// 1 <= S.length <= 200
// 字符串 S 中只含有数字。s

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    inline bool equal(const string& S, const int& s, const int& i, const int& j, int& k){
        int64_t k_int = int64_t(atoi(S.substr(s, i-s).c_str())) + atoi(S.substr(i, j-i).c_str());
        if (k_int > INT32_MAX) return false;
        string k_i = to_string(k_int);
        k = j + k_i.size();
        bool r = S.substr(j, k_i.size()) == k_i;
        return r;
    }
    vector<int> splitIntoFibonacci(string S) {
        int num1 = 0, num2 = 0;
        vector<int> select_idx(2);
        for(int i = 0; i < min(int(S.size()-1)/2, 10) ; ++i){
            select_idx[0] = i+1;
            for(int j = i+1; j < min(int(2 * S.size()) / 3, i+10); j++){
                select_idx[1] = j+1;
                select_idx.resize(2);
                int s = 0, n1 = i+1, n2 = j+1, n3 = 0;
                while(equal(S, s, n1, n2, n3)){
                    select_idx.push_back(n3);
                    if (n3 == S.size()){
                        vector<int> results;
                        results.reserve(select_idx.size());
                        int pre = 0;
                        for(auto& k : select_idx){
                            results.push_back(atoi(S.substr(pre, k - pre).c_str()));
                            pre = k;
                        }
                        return results;
                    }
                    s = n1;
                    n1 = n2;
                    n2 = n3;
                }
                
            }
        }
        return vector<int>{};
    }
};

int main(){
    vector<int> ss = Solution().splitIntoFibonacci("3611537383985343591834441270352104793375145479938855071433500231900737525076071514982402115895535257195564161509167334647108949738176284385285234123461518508746752631120827113919550237703163294909");
    for(auto& s : ss){
        cout << s << endl;
    }
    cout << endl;
}

// Line 4: Char 63: runtime error: signed integer overflow: 2147483647 + 2 cannot be represented in type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:14:63