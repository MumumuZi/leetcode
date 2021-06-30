// 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。

// 示例:

// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// 说明：

// 所有输入均为小写字母。
// 不考虑答案输出的顺序。

#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> all_str;
        vector<char> buckets;
        string order_str;
        for(auto& str : strs){
            buckets = vector<char>(26, 0);
            order_str.clear();
            for(auto& c : str){
                buckets[c - 'a'] += 1;
            }
            for(int i=0; i < buckets.size(); ++i){
                if(buckets[i] != 0){
                    order_str.append(buckets[i], 'a' + i);
                }
            }
            if (all_str.find(order_str) == all_str.end()){
                all_str[order_str] = vector<string>{str};
            }else{
                all_str[order_str].push_back(str);
            }
        }
        vector<vector<string>> results;
        for(auto& kv : all_str){
            results.push_back(std::move(kv.second));
        }
        return results;
    }
};

int main(){
    vector<string> strs{};
    vector<vector<string>> results = Solution().groupAnagrams(strs);
    for(auto& v : results){
        for(auto& s : v){
            cout << s << " ";
        }
        cout << "\n";
    }
}