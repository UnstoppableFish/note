#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
using namespace std;

// class Solution{
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             for(int i = 0;i < nums.size() - 1;i++){
//                 for(int j = i + 1;j < nums.size();j++){
//                     if((nums[i] + nums[j]) == target){
//                         return vector<int>{i,j};
//                     }
//                 }
//             }
//         }

// };

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            if(n == 0){
                return {};
            }

            unordered_map<int,int> ti;
            for(int i = 0;i < n;i++){
                auto vi = ti.find(target - nums[i]);
                if(vi != ti.end()){
                    return {vi->second,i};
                }
                ti[nums[i]] = i;
            }
            return {};
        }
};