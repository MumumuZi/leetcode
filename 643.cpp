// 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。

//  

// 示例：

// 输入：[1,12,-5,-6,50,3], k = 4
// 输出：12.75
// 解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double max_avg = accumulate(nums.begin(), nums.begin()+k, 0.0)/k;
        double pre_avg = max_avg;
        for(int i = k; i < nums.size(); ++i){
            pre_avg = pre_avg + double(nums[i]-nums[i-k])/k;
            max_avg = max(max_avg, pre_avg);
        }
        return max_avg;
    }
};