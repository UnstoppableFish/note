#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
            return {};
        }

        vector<int> ti;
        vector<int> vi;
        int max;
        for(int i = 0;i < n - k + 1;i++){
            for(int j = i;j < i + k;j++){
                ti.push_back(nums[j]);
                max = *max_element(ti.begin(),ti.end());
                
            }
            vi.push_back(max);
            ti.clear();
        }
        return vi;
    }
};