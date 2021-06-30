// 给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。

// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。）

// 示例 1:

// 输入: N = 10
// 输出: 9
// 示例 2:

// 输入: N = 1234
// 输出: 1234
// 示例 3:

// 输入: N = 332 1200 122000
// 输出: 299
// 说明: N 是在 [0, 10^9] 范围内的一个整数。
#include <cmath>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int i = 0;
        for(; i < s.size()-1; ++i){
            if(s[i] > s[i+1]) break;
        }
        if(i == s.size()-1) return stoi(s);
        if (i == 0){
            s[i] -= 1;
        }else{
            while(i >= 0){
                if(s[i]-1 >= s[i-1]){
                    s[i] -= 1;
                    break;
                }
                --i;
            }
        }
        return stoi(s.substr(0, i+1).append(s.size()-1 - i, '9'));
    }
};
//100 090

int main(){
    cout << Solution().monotoneIncreasingDigits(1200) << endl;
}