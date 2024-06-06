#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0){
            return {};
        }
        if(n == 1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ti;
        for(int i = 0;i < n;i++){
            int l = intervals[i].front();
            int r = intervals[i].back();
            if(ti.empty() || ti.back()[ti.back().size() - 1] < l){
                ti.push_back({l,r});
            }
            else{
                ti.back()[ti.back().size() - 1] = max(r,ti.back()[ti.back().size() - 1]);
            }
        }
        
        return ti;
    }
};
