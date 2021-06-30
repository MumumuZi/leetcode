#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int max_ret = 0;
        int r = 0;
        for(int i = 0; i < t.size(); ++i){
            r = max(r, i);
            cout << "start" << i << maxCost << endl;
            while(r < s.size()){
                maxCost -= abs(t[r]-s[r]);
                if(maxCost < 0){
                    maxCost += abs(t[r]-s[r]);
                    break;
                }
                r++;
            }
            max_ret = max(max_ret, r - i);
            if(i != r)
                maxCost += abs(t[i]-s[i]);
            cout << i << r << endl;
            if (r == s.size()-1) return max_ret;
        }
        return max_ret;
    }
};

int main(){
//     "abcd"
// "cdef"
// 1
    cout << Solution().equalSubstring("abcd", "cdef", 1);
}