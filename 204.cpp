// 统计所有小于非负整数 n 的质数的数量。

//  

// 示例 1：

// 输入：n = 10
// 输出：4
// 解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7, 11,13,17
// 示例 2：
//2,3,5,7,11
//13,17,19,23

// 输入：n = 0
// 输出：0
// 示例 3：

// 输入：n = 1
// 输出：0
//  

// 提示：

// 0 <= n <= 5 * 106 = 530

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        int max_n = 23;
        int devide_n = 2;
        vector<int> nums(n-2);
        for(int i = 0; i < nums.size(); i++) nums[i] = i+2;
        int v = 0;
        while(devide_n <= max_n){
            for(int i = 0; i < nums.size(); ++i){
                v = nums[i]; 
                if(v != -1 && v != devide_n && v % devide_n == 0) nums[i] = -1;
            }
            ++devide_n;
        }
        int count = 0;
        for(auto& i : nums){
            if(i != -1) ++count;
        }
        return count;
    }
};

int main(){
    std::cout << Solution().countPrimes(10) << std::endl;
}