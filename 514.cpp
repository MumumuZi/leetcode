#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>


using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, int> key_m;
        for(auto& c : key){
            if(key_m.find(c) == key_m.end()){
                key_m[c] = 1;
            }else{
                key_m[c] +=1;
            }
        }
        //idx, need: 
        vector<pair<int, int>> best_points;
        unordered_map<char, vector<int>> best_points_m;
        for (size_t i = 0; i < ring.size(); i++)
        {
            char c = ring[i];
            if(key_m.find(c) != key_m.end()){
                best_points.emplace_back(i, key_m[c]);
                if (best_points_m.find(c) == best_points_m.end()){
                    best_points_m[c] = vector<int>{int(key_m[c])};
                }else{
                    best_points_m[c].push_back(key_m[c]);
                }
            }
        }
        //now 0
        int point_n = best_points.size();
        int ring_n = ring.size();

        int now_ring_idx = 0;
        int to_left = 0;
        int to_right = 0;

        int total = 0;
        if(best_points_m.find(ring[0]) == best_points_m.end()){
            total += best_points[0].second;
            best_points.insert(best_points.begin(), pair<int, int>(0, 0));
        }else{
            total += best_points[0].second;
            for(auto& i : best_points_m[ring[now_ring_idx]]){
                best_points[i].second = 0;
                cout << "reset" << i << endl;
            }
        }
        cout << best_points.size() << endl;
        
        int select_i = 0;
        int left = best_points.size()-1, right = 1;
        while (left >= right){
            while(best_points[left].second == 0) --left;
            while(best_points[right].second == 0) ++right;
            cout << "while " << now_ring_idx << " " << total << " " << left << " " << right <<  endl;
            if (left < right) break;
            to_left = best_points[left].first > now_ring_idx ? ring_n - best_points[left].first + now_ring_idx : now_ring_idx - best_points[left].first;
            to_right = now_ring_idx > best_points[right].first ? ring_n - now_ring_idx + best_points[right].first : best_points[right].first - now_ring_idx;

            if (to_left < to_right){
                total += (to_left + best_points[left].second);
                now_ring_idx = best_points[left].first;
                --left;
            }else{
                total += (to_right + best_points[right].second);
                now_ring_idx = best_points[right].first;
                ++right;
            }
            for(auto& i : best_points_m[ring[now_ring_idx]]){
                best_points[i].second = 0;
            }
            cout << ring[now_ring_idx] << " " << now_ring_idx << " " << to_left << " " << to_right << " " << total << " " << left << " " << right <<  endl;
        }
        return total;
    }
};

int main(){
    int step = Solution().findRotateSteps("godding", "gd");
    cout << step << endl;
}
