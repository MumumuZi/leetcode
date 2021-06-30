
// 给定一个字符串S，检查是否能重新排布其中的字母，使得两相邻的字符不同。

// 若可行，输出任意可行的结果。若不可行，返回空字符串。

// 示例 1:

// 输入: S = "aab"
// 输出: "aba"
// 示例 2:

// 输入: S = "aaab"
// 输出: ""
// 注意:

// S 只包含小写字母并且长度在[1, 500]区间内。
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        vector<int> letters(26);
        for(auto& c : S){
            letters[c - 'a'] += 1;
        }
        vector<int> counts(500);
        for(int i = 0; i < letters.size(); ++i){
            counts[letters[i]] = i + 'a';
        }
        vector<pair<int, int>> count_pair;
        for(int i = counts.size()-1; i >=0; --i){
            if(counts[i] != 0){
                count_pair.push_back(pair<int, int>(counts[i], i));
            }
        }
        if(count_pair[0].second > (S.size() + 1)/2) return "";
        string results(S.size(), 0);
        int idx = 0;
        while (true){
            for(auto& p : count_pair){
                if (p.second != 0){
                    results[idx] = p.first;
                    ++idx;
                    --p.second;
                }
            }
            if(idx == S.size()) return results;
        }
    }
};

int main(){
    cout << Solution().reorganizeString("vvvlo") << endl;
}