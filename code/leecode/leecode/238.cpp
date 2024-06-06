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
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return {};
        }

        vector<int> li(n);
        vector<int> ri(n);

        li[0] = 1;
        for(int i = 1;i < n;i++){
            li[i] = li[i - 1] * nums[i - 1];
        }

        ri[n - 1] = 1;
        for(int i = n - 2;i >= 0;i--){
            ri[i] = ri[i + 1] * nums[i + 1];
        }

        vector<int> ou(n);
        for(int i = 0;i < n;i++){
            ou[i] = ri[i] * li[i];
        }
        return ou;
    }
};