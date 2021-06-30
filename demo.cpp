#include <vector>
#include <iostream>

using namespace std;

int binary_find(vector<int> num, int n){
    int l = 0;
    int r = num.size()-1;
    while(l < r){
        int m = l + (r-l)/2;
        if (n > num[m]){
            l = m+1;
        }else{
            r = m;
        }
    }
    return num[l] == n ? l : -1;
}

void binary_insert(vector<int>& num, int n){
    if (num.empty()){
        num.push_back(n);
        return;
    }
    int l = 0;
    int r = num.size()-1;
    while(l < r){
        int m = l + (r-l)/2;
        if (n > num[m]){
            l = m+1;
        }else{
            r = m;
        }
    }
    if(n > num[l]){
        num.push_back(n);
    }else{
        num.insert(num.begin()+l, n);
    }
}

int partion(vector<int>& nums, int i, int j){
    int l = i;
    int r = j;
    int n = nums[l];
    while(l < r){
        while(nums[r] >= n && r > l) r--;
        nums[l] = nums[r];
        while(nums[l] <= n && l < r) l++;
        nums[r] = nums[l];
    }
    nums[l] = n;
    return l;
    // quick_sort_one(nums, i, l-1);
    // quick_sort_one(nums, l+1, j);
}

int quick_find_k(vector<int>& nums, int i, int j, int k){
    if (k < i || k > j) return -1;
    int n = partion(nums, i, j);
    if (n > k){
        return quick_find_k(nums, i, n-1, k);
    }else if (n < k){
        return quick_find_k(nums, n+1, j, k);
    }else{
        return nums[n];
    }
}

void find_combine(vector<int>& nums, vector<vector<int>>& ans, vector<int>& arr, int n, int target){
    if (target == 0){
        ans.push_back(arr);
        return;
    }
    if (n == nums.size()) return;
    //不要n
    find_combine(nums, ans, arr, n+1, target);
    //要n
    if (target >= nums[n]){
        arr.push_back(nums[n]);
        find_combine(nums, ans, arr, n+1, target-nums[n]);
        arr.pop_back();
    }

}

vector<vector<int>> sum_of_array(vector<int>& nums, int target){
    vector<vector<int>> ans;
    vector<int> arr;
    find_combine(nums, ans, arr, 0, target);
    return ans;
}

int main(){
    vector<int> nums{10, 1,2,7,6,1,5};
    // cout << quick_find_k(nums, 0, nums.size()-1, 100) << endl;
    vector<vector<int>> ans = sum_of_array(nums, 8);
    for(auto& vv : ans){
        for(auto& v : vv){
            cout << v << " ";
        }
        cout << endl;
    }
}