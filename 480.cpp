// 中位数是有序序列最中间的那个数。如果序列的长度是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

// 例如：

// [2,3,4]，中位数是 3
// [2,3]，中位数是 (2 + 3) / 2 = 2.5
// 给你一个数组 nums，有一个长度为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

//  

// 示例：

// 给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

// 窗口位置                      中位数
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       1
//  1 [3  -1  -3] 5  3  6  7      -1
//  1  3 [-1  -3  5] 3  6  7      -1
//  1  3  -1 [-3  5  3] 6  7       3
//  1  3  -1  -3 [5  3  6] 7       5
//  1  3  -1  -3  5 [3  6  7]      6
//  因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

// //  

// 提示：

// 你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
// 与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    void insert_sort(vector<int>& vec, int v, bool add){
        if(vec.empty()){
            vec.push_back(v);
            return;
        }
        int l = 0;
        int r = vec.size()-1;
        while(l < r){
            int m = l + (r-l)/2;
            if(v < vec[m]){
                r = m;
            }else if (v > vec[m]){
                l = m + 1;
            }else{
                l = r = m;
            }
        }
        if(!add){
            vec.erase(vec.begin() + r);
        }else if(v > vec.back()){
            vec.push_back(v);
        }else{
            cout << "insert" << l << r << endl;
            vec.insert(vec.begin() + max(r, 0), v);
        }
    }
    inline double get_zws(vector<int>& vec){
        return vec.size()%2==0 ? double(long(vec[vec.size()/2]) + long(vec[vec.size()/2-1]))/2 : vec[vec.size()/2];
    }
    void p_vec(vector<int>& v){
        for(auto& vv: v){
            cout << vv;
        }
        cout << endl;
        
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec(nums.begin(), nums.begin()+k);
        sort(vec.begin(), vec.end());
        vector<double> result{get_zws(vec)};
        result.reserve(nums.size()-k+1);
        for(int i = k; i < nums.size(); i++){
            p_vec(vec);
            insert_sort(vec, nums[i-k], false);
            p_vec(vec);
            insert_sort(vec, nums[i], true);
            p_vec(vec);
            result.push_back(get_zws(vec));
            cout << endl;
        }
        return result;
    }
};

int main(){
    vector<int> nums{7,0,3,9,9,9,1,7,2,3};
    vector<double> result = Solution().medianSlidingWindow(nums, 6);
    for(auto& d : result){
        cout << d;
    }

}