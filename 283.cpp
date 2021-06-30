#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_s = -1;
        int zero_e = -1;
        int tmp;
        for(int i = 0; i < nums.size(); ++i){
            if (nums[i] == 0){
                zero_e = i;
                if (zero_s == -1){
                    zero_s = i;
                }
                continue;
            }
            if (zero_s != -1){
                nums[zero_s] = nums[i];
                nums[i] = 0;
                ++zero_e;
                ++zero_s;
            }
        }
    }
};

int main(){
    vector<int> nums{0,0,2,2,1};
    //1 0 0
    //0 1 0
    //0 1 0
    Solution().moveZeroes(nums);
    for(auto& i : nums){
        cout << i;
    }
    cout << endl;
}

// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 示例:

// 输入: [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 说明:

// 必须在原数组上操作，不能拷贝额外的数组。
// 尽量减少操作次数。