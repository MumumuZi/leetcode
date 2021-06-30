#include <unordered_map>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, vector<int>> nums;
    vector<int> history;
    default_random_engine e;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        history.push_back(val);
        if(nums.find(val) == nums.end()){
            nums[val] = vector<int>();
        }
        nums[val].push_back(history.size()-1);
        return nums[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(nums.find(val) != nums.end() && nums[val].size() != 0){
            int his_idx = *nums[val].begin(); //0
            nums[val].erase(nums[val].begin());
            if (his_idx != history.size()-1){
                int last = history[history.size()-1]; //1
                nums[last][nums[last].size()-1] = his_idx;
                cout << nums[val].size() << last << endl;
                history[his_idx] = last;
                cout << "set his" << val << his_idx << last << endl;
                cout << "nums[" << last << "]";
                for(auto& i : nums[last]){
                    cout << i;
                }
                cout << endl;
            }
            
            history.erase(history.end()-1);

            cout << "remove " << val << endl;
            for(auto i : history){
                cout << " " << i << endl;
            }

            return true;
        }else{
            return false;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return history[e()%history.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(int argc, char const *argv[])
{
    RandomizedCollection r;
    r.insert(1);
    r.insert(1);
    r.insert(2);
    r.insert(1);
    r.insert(2);
    r.insert(2);

    r.remove(1);
    r.remove(2);
    r.remove(2);
    r.remove(2);
    // cout << r.getRandom() << r.getRandom() << r.getRandom()  << endl;
    //112122
    //
    return 0;
}
//1 2 1