#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1;
        int l = 0;
        int ax = 0;
        while(l < r){
            int area = (r - l) * min(height[l],height[r]);
            ax = max(ax,area);
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return ax;
    }
};