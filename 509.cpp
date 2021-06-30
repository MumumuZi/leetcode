#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        vector<int> cache(n+1, 0);
        for(int i = 0; i <= n; i++){
            if (i < 2){
                cache[i] = i;
            }else{
                cache[i] = cache[i-1] + cache[i-2];
            }
        }
        return cache[n];
    }
};

int main(){
    std::cout << Solution().fib(4) << std::endl;
}