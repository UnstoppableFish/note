#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        if(len < 3){
            return {};
        }
        sort(nums.begin(),nums.end());
        vector<vector<int>> ma;
        for(int i = 0;i < len ;i++){
            if(nums[i] > 0){
                return ma;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int l = i + 1;
            int r = len - 1;
            while(l < r){
                if((nums[l] + nums[i] + nums[r]) == 0){
                    ma.push_back({nums[i],nums[l],nums[r]});
                    while(l < r && nums[l] == nums[l + 1]){
                        l++;
                    }
                    while(l < r && nums[r] == nums[r - 1]){
                        r--;
                    }
                    r--;l++;
                }
                else if((nums[l] + nums[i] + nums[r]) > 0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ma;
    }
};