#include <vector>
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

int find_count(int preffix, int n){
    int cnt = 0;
    int next = preffix+1;
    while(preffix < n){
        cnt += min(next, n+1) - preffix;
        preffix *= 10;
        next *= 10;
    }
    return cnt;
}

int dictIdxK(int n, int k){
    int preffix = 1;
    int pos = 1;
    while(pos < k){
        int cnt = find_count(preffix, n);
        // cout << preffix << ", " << n << "," << cnt << "," << pos << endl;
        if (k < pos + cnt){
            //内部
            preffix *= 10;
            pos++;
        }else{
            preffix ++;
            pos += cnt;
        }
    }
    return preffix;
}

int main(){
    cout << dictIdxK(13, 7) << endl;
}