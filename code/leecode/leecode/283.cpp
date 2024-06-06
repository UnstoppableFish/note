#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0){
            return;
        }
        int index = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] != 0){
                nums[index] = nums[i];
                index++;
            }
        }
        for(int j = index;j < nums.size();j++){
            nums[j] = 0;
        }
    }
};