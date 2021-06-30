#include <vector>
#include <iostream>
using namespace std;

// [[1,2],[3,5],[6,7],[8,10],[12,16]]
// [4,8]
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0){
            return vector<vector<int>>{newInterval};
        }
        int insert_into = 0;
        int& start = newInterval[0];
        int& end = newInterval[1];
        auto& first = intervals[0];
        auto& last = intervals[intervals.size()-1];
        if (start <= first[0] && end >= last[1]){
            return vector<vector<int>>{newInterval};
        }
        for(auto it = intervals.begin();it != intervals.end();){
            int& a = it->at(0);
            int& b = it->at(1);
            if (start > b){
                ++insert_into;
                ++it;
                continue;
            }else{
                start = a > start ? start : a;
                auto it_end = it;
                for (;it_end != intervals.end();){
                    int& c = it->at(0);
                    int& d = it->at(1);
                    if(end < c){
                        break;
                    }else if (end >= c && end <= d){
                        end = d;
                        intervals.erase(it_end);
                        break;
                    }else{
                        it_end = intervals.erase(it_end);
                        continue;
                    }
                }
                break;
            }
        }
        intervals.insert(intervals.begin()+insert_into, newInterval);
        return intervals;
    }
};

int main(int argc, char const *argv[])
{
    auto intervals = vector<vector<int>>{vector<int>{0,5}, vector<int>{9,12}};
    auto newInterval = vector<int>{7,16};
    auto res = Solution().insert(intervals, newInterval);
    for(auto& i : res){
        cout << "[" << i[0] << " " << i[1] << "]" << " ";
    }
    return 0;
}

// [[0,5],[9,12]]
// [7,16]