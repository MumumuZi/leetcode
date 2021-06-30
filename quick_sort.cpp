#include <iostream>
#include <vector>

void quick_sort(std::vector<int>& nums, int low, int high){
    if (low >= high) return;
    int i = low, j = high, pivot = nums[low];
    while(i < j){
        while(i < j && nums[j] >= pivot){--j;}
        nums[i] = nums[j];
        while(i < j && nums[i] <= pivot){++i;}
        nums[j] = nums[i];
    }
    nums[i] = pivot;
    quick_sort(nums, low, i-1);
    quick_sort(nums, i+1, high);
}
int main(){
    std::vector<int> nums{1,3,2,5,7,4,9,0};
    quick_sort(nums, 0, nums.size()-1);
    for(auto& i : nums){
        std::cout << i << std::endl;
    }
}