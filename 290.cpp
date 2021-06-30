// 给定一种规律 pattern 和一个字符串 str ，判断 str 是否遵循相同的规律。

// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 str 中的每个非空单词之间存在着双向连接的对应规律。

// 示例1:

// 输入: pattern = "abba", str = "dog cat cat dog"
// 输出: true
// 示例 2:

// 输入:pattern = "abba", str = "dog cat cat fish"
// 输出: false
// 示例 3:

// 输入: pattern = "aaaa", str = "dog cat cat dog"
// 输出: false
// 示例 4:

// 输入: pattern = "abba", str = "dog dog dog dog"
// 输出: false
// 说明:
// 你可以假设 pattern 只包含小写字母， str 包含了由单个空格分隔的小写字母。    
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<std::string> mapping(26, std::string{});
        unordered_set<std::string> words;
        int idx_p = 0;
        int idx_s = 0;
        std::string sub_str;
        int m_idx = 0;
        for(; idx_p < pattern.size(); ++idx_p){
            sub_str.clear();
            for(;idx_s < s.size(); ++idx_s){
                if(s[idx_s] == ' '){
                    ++idx_s;
                    break;
                }
                sub_str.append(1, s[idx_s]);
            }
            if (sub_str.size() == 0) return false;
            m_idx = pattern[idx_p]-'a';
            if(mapping[m_idx].size() == 0){
                if (words.find(sub_str) != words.end()){
                    return false;
                }
                words.insert(sub_str);
                mapping[m_idx] = sub_str;
            }else if(mapping[m_idx] != sub_str){
                return false;
            }
        }
        return idx_s == s.size();
    }
};

int main(){
// "he"
// "unit"
    cout << Solution().wordPattern("he", "aaa") << endl;
}