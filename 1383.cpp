// 公司有编号为 1 到 n 的 n 个工程师，给你两个数组 speed 和 efficiency ，其中 speed[i] 和 efficiency[i] 分别代表第 i 位工程师的速度和效率。请你返回由最多 k 个工程师组成的 ​​​​​​最大团队表现值 ，由于答案可能很大，请你返回结果对 10^9 + 7 取余后的结果。

// 团队表现值 的定义为：一个团队中「所有工程师速度的和」乘以他们「效率值中的最小值」。

//  

// 示例 1：
//[2, 10, 3, 1,5,8]
//[5, 4,  3, 9,7,2]
//
// 输入：n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 2
// 输出：60
// 解释：
// 我们选择工程师 2（speed=10 且 efficiency=4）和工程师 5（speed=5 且 efficiency=7）。他们的团队表现值为 performance = (10 + 5) * min(4, 7) = 60 。
// 示例 2：

// 输入：n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 3
// 输出：68
// 解释：
// 此示例与第一个示例相同，除了 k = 3 。我们可以选择工程师 1 ，工程师 2 和工程师 5 得到最大的团队表现值。表现值为 performance = (2 + 10 + 5) * min(5, 4, 7) = 68 。
// 示例 3：

// 输入：n = 6, speed = [2,10,3,1,5,8], efficiency = [5,4,3,9,7,2], k = 4
// 输出：72
//  

// 提示：

// 1 <= n <= 10^5
// speed.length == n
// efficiency.length == n
// 1 <= speed[i] <= 10^5
// 1 <= efficiency[i] <= 10^8
// 1 <= k <= n
#include <vector>
#include <unordered_set>
#include <math.h>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        unordered_set<int> selected;
        int sum = 0, min_eff = INT32_MAX;
        long long score = 0;
        int new_sum = 0, new_min_eff = 0;
        long long new_score = 0;
        int choice_sum = 0, choice_min_eff = 0;
        long long choice_score = 0;
        int new_selected = 0;
        long long max_score = 0;
        for(int i = 0; i < k; ++i){
            choice_score = 0;
            for(int j = 0; j < speed.size(); ++j){
                if (selected.find(j) != selected.end()) continue;
                new_sum = sum + speed[j];
                new_min_eff = min(min_eff, efficiency[j]);
                new_score = new_sum * new_min_eff;
                if (new_score > choice_score){
                    choice_score = new_score;
                    choice_sum = new_sum;
                    choice_min_eff = new_min_eff;
                    new_selected = j;
                }
            }
            score = choice_score;
            sum = choice_sum;
            min_eff = choice_min_eff;
            
            selected.insert(new_selected);
            if(score > max_score) max_score = score;
        }
        return max_score % (10^9 + 7);
    }
};

//[2, 10, 3, 1,5,8]
//[5, 4,  3, 9,7,2]
// 6

// [10,5,1,7,4,2] 29
// [2,1,1,1,7,3] 2
// 6
//32

int main(){
    cout << 32 % (10^9 + 7);
    return 0;
    vector<int> speed{10,5,1,7,4,2};
    vector<int> efficiency{2,1,1,1,7,3};
    cout << Solution().maxPerformance(speed.size(), speed, efficiency, 5) << endl;
}