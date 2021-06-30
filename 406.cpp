// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// [4,4] [5,2] [5,0] [6,1] [7,1] [7,0]

// [4,4] [5,0]  [7,0] [6,1] [7,1]

//  [5,0]   [7,0] [5,2]  [6,1] [4,4] [7,1]
// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool my_sorter(vector<int> a,  vector<int> b){
        if (a[0] > b[0]) return false;
        if(a[0] == b[0]) return a[1] > b[1];
        return true;
    }

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        std::sort(people.begin(), people.end(), my_sorter);
        int new_pos = 0;
        vector<int> tmp;
        for (int i = people.size()-1; i >= 0 ; --i)
        {
            new_pos = i + people[i][1];
            if (new_pos != i && new_pos < people.size()){
                tmp = people[i];
                people.erase(i + people.begin());
                people.insert(new_pos + people.begin(), tmp);
            }
        }
        return people;
    }
};

int main(int argc, char const *argv[])
{
    //[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]
    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    Solution().reconstructQueue(people);
    for (auto& p : people){
        cout << p[0] << "," << p[1] << " ";
    }
    return 0;
}
