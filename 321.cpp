// 给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。

// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。

// 说明: 请尽可能地优化你算法的时间和空间复杂度。

// 示例 1:

// 输入:
// nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
//num = 9, 1,2,5,8,3,4,6,5,3
//9,8,6,5,3
// k = 5
// 输出:
// [9, 8, 6, 5, 3]
// 示例 2:

// 输入:
// nums1 = [6, 7]
// nums2 = [6, 0, 4]
// k = 5
// 输出:
// [6, 7, 6, 0, 4]
// 示例 3:

// 输入:
// nums1 = [3, 9]
// nums2 = [8, 9]
// k = 3
// 输出:
// [9, 8, 9]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/create-maximum-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> num_vec1(10);
        vector<vector<int>> num_vec2(10);
        for(int i = 0; i < size1; ++i) num_vec1[nums1[i]].push_back(i);
        for(int i = 0; i < size2; ++i) num_vec2[nums2[i]].push_back(i);
        vector<int> results;
        int size = size1 + size2;
        int v1_idx = -1, v2_idx = -1;
        int v1_idx_tmp = 0, v2_idx_tmp = 0;
        for(int i = 9; i >= 0; --i){
            if(results.size() == k) return results;
            if(num_vec1[i].size() != 0){
                v1_idx_tmp = num_vec1[i][0];
                if(v1_idx_tmp >= v1_idx && (k - results.size()) <= (size - v1_idx_tmp - v2_idx - 1)){
                    v1_idx = v1_idx_tmp;
                    num_vec1[i].erase(num_vec1[i].begin());
                    results.push_back(i);
                    i = 10;
                    continue;
                }
            }
            if(num_vec2[i].size() != 0){
                v2_idx_tmp = num_vec2[i][0]; 
                if(v2_idx_tmp >= v2_idx && (k - results.size()) <= (size - v2_idx_tmp - v1_idx - 1)){
                    v2_idx = v2_idx_tmp;
                    num_vec2[i].erase(num_vec2[i].begin());
                    results.push_back(i);
                    i = 10;
                    continue;
                }
            }

        }
        return results;
    }
};

int main(){
    vector<int> num1{8, 9};
    vector<int> num2{3, 9};
    vector<int> result = Solution().maxNumber(num1, num2, 3);
    for(auto i : result){
        cout << i;
    }
}