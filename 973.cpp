#include <vector>
#include <math.h>

using namespace std;

inline int square(vector<int>& point){
    return point[0] * point[0] + point[1] * point[1];
}

int find_pivot(vector<vector<int>>& points, int low, int high){
    if (low >= high) return;
    int pivot = square(points[high]);
    vector<int>& pivot_v = points[high];
    while(low < high){
        while(low < high && square(points[high]) >= pivot){--high;}
        points[low] = points[high];
        while(low < high && square(points[low]) <= pivot){++low;}
        points[high] = points[low];
    }
    points[low] = pivot_v;
    return low;
}

vector<vector<int>> find_k(vector<vector<int>>& points, int k, int low, int high){
    int pivot = find_pivot(points, low, high);
    if (pivot == k-1){
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }
    return pivot < k ? find_k(points, k, pivot+1, high) : find_k(points, k, low, pivot-1)
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

    }
};
