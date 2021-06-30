// 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

//  

// 示例 1：

// 输入：k = 2, prices = [2,4,1]
// 输出：2
// 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
// 示例 2：

// 输入：k = 2, prices = [3,2,6,5,0,3]
// 输出：7
// 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//      随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。
//  

// 提示：

// 0 <= k <= 109
// 0 <= prices.length <= 1000
// 0 <= prices[i] <= 1000
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k < 1) return 0;
        vector<int> change;
        int sum = 0;
        int add = 0;
        for(int i = 0; i < prices.size()-1; i++){
            if(prices[i+1] > prices[i] && add == 1){
                change.push_back(sum);
                sum = 0;
            }else if(prices[i+1] < prices[i] && add == 2){
                change.push_back(sum);
                sum = 0;
            }
            if (prices[i+1] > prices[i]){
                add = 2;
            }else if(prices[i+1] < prices[i]){
                add = 1;
            }
            sum += prices[i+1] - prices[i];
        }
        change.push_back(sum);
        
        int max_p = 0;
        int max_i = 0;
        int total = 0;
        unordered_set<int> used;
        for(int i = 0; i < k; i++){
            max_p = 0;
            max_i = 0;
            for(int j = 0; j < change.size(); j++){
                if (change[j] <= 0 || used.find(j) != used.end()){
                    continue;
                }
                if (change[j] > max_p){
                    max_p = change[j];
                    max_i = j;
                }
            }
            if(max_p <= 0){
                break;
            }
            total += max_p;
            used.insert(max_i);
        }


        for(int i = 0; i < change.size(); i++){
            if(used.find(i) == used.end()) continue;
            int tmp_sum = 0;
            int temp_max = 0;
            for(int j = i-1; j >= 0; j--){
                if (used.find(j) != used.end()){
                    break;
                }
                tmp_sum += change[j];
                if(tmp_sum > temp_max){
                    temp_max = tmp_sum;
                }
            }
            if(temp_max > 0){
                total += temp_max;
                cout << i << temp_max << endl;
            }

            
            tmp_sum = 0;
            temp_max = 0;
            int max_j = 0;
            for(int j = i+1; j < change.size(); j++){
                if (used.find(j) != used.end()){
                    break;
                }
                tmp_sum += change[j];
                if(tmp_sum > temp_max){
                    temp_max = tmp_sum;
                    max_j = j;
                }
            }
            if(temp_max > 0){
                total += temp_max;
                used.insert(max_j);
                cout << i << temp_max << endl;
            }
            
        }

        return total;
    }
};

int main(){
    //
    //4，-1，4，-4，3
    vector<int> price{1,5,4,8,4,7};
    cout << Solution().maxProfit(2, price);
}