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
    int maxSubArray(vector<int>& nums) {
       int n = nums.size();
       if(n == 0){
        return 0;
       } 

        vector<int> ti(n);
        ti[0] = nums[0];

        for(int i = 1;i < n;i++){
            if(ti[i - 1] > 0){
                ti[i] = ti[i - 1] + nums[i];
            }
            else{
                ti[i] = nums[i];
            }
        }

        int ma = nums[0];
        for(int i = 0;i < n;i++){
            ma = max(ti[i],ma);
        }

        return ma;
    }
};