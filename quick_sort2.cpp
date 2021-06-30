#include <vector>
#include <iostream>
#include <algorithm>

void quick_sort(int left, int right, std::vector<int>& nums){
    if (left >= right) return;
    int pivot = nums[left];
    int p_left = left, p_right = right;
    while(p_left != p_right){
        while(p_left != p_right && nums[p_right] >= pivot) --p_right;
        nums[p_left] = nums[p_right];
        while(p_left != p_right && nums[p_left] <= pivot) ++p_left;
        nums[p_right] = nums[p_left];
    }
    nums[p_left] = pivot;
    quick_sort(left, p_left-1, nums);
    quick_sort(p_left+1, right, nums);
}

void sort(std::vector<int>& nums){
    quick_sort(0, nums.size()-1, nums);
}

int main(){
    std::vector<int> nums{1,3,5,7,9, 2,4,6,8,0};
    sort(nums);
    for(auto& n : nums){
        std::cout << n << std::endl;
    }
}