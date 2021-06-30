
// 给定一个列表 accounts，每个元素 accounts[i] 是一个字符串列表，其中第一个元素 accounts[i][0] 是 名称 (name)，其余元素是 emails 表示该账户的邮箱地址。

// 现在，我们想合并这些账户。如果两个账户都有一些共同的邮箱地址，则两个账户必定属于同一个人。请注意，即使两个账户具有相同的名称，它们也可能属于不同的人，因为人们可能具有相同的名称。一个人最初可以拥有任意数量的账户，但其所有账户都具有相同的名称。

// 合并账户后，按以下格式返回账户：每个账户的第一个元素是名称，其余元素是按字符 ASCII 顺序排列的邮箱地址。账户本身可以以任意顺序返回。

//  

// 示例 1：

// 输入：
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// 输出：
// [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// 解释：
// 第一个和第三个 John 是同一个人，因为他们有共同的邮箱地址 "johnsmith@mail.com"。 
// 第二个 John 和 Mary 是不同的人，因为他们的邮箱地址没有被其他帐户使用。
// 可以以任何顺序返回这些列表，例如答案 [['Mary'，'mary@mail.com']，['John'，'johnnybravo@mail.com']，
// ['John'，'john00@mail.com'，'john_newyork@mail.com'，'johnsmith@mail.com']] 也是正确的。
//  

// 提示：

// accounts的长度将在[1，1000]的范围内。
// accounts[i]的长度将在[1，10]的范围内。
// accounts[i][j]的长度将在[1，30]的范围内。

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, string&> mails;
        unordered_set<string> cache;
        for(int i = 0; i < accounts.size(); i++){
            string name = accounts[i][0] + "_" + std::to_string(i);
            bool repeat = false;
            cache.clear();
            for(int j = 1; j < accounts[i].size(); j++){
                if(cache.find(accounts[i][j]) != cache.end()) continue;
                cache.insert(accounts[i][j]);

                if(mails.find(accounts[i][j]) != mails.end()){
                    repeat = true;
                    name = mails[accounts[i][j]];
                    break;
                }
                mails[accounts[i][j]] = name;
            }
            if(repeat){
                for(int j = 1; j < accounts[i].size(); j++){
                    mails[accounts[i][j]] = name;
                }
            }
        }
        unordered_map<string, unordered_set<string>> mails2;
        for(auto v : mails){
            mails2[v.second].insert(v.first);
        }
        vector<vector<string>> results;
        for(auto v : mails2){
            sort(v.second.begin(), v.second.end());
            int i = v.first.size();
            for(; i >= 0; i--){
                if(v.first[i] == '_'){
                    break;
                }
            }
            results.emplace_back(v.first.substr(i));
            for(auto& n : v.second){
                results.emplace_back(n);
            }
        }
        return results;
    }
};

int main(){

}

// [["David","David0@m.co","David4@m.co","David3@m.co"],["David","David5@m.co","David5@m.co","David0@m.co"],["David","David1@m.co","David4@m.co","David0@m.co"],["David","David0@m.co","David1@m.co","David3@m.co"],["David","David4@m.co","David1@m.co","David3@m.co"]]
[["David","David5@m.co"],["David","David0@m.co","David1@m.co","David3@m.co","David4@m.co"]]
[["David","David0@m.co","David1@m.co","David3@m.co","David4@m.co","David5@m.co"]]