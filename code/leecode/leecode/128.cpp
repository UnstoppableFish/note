#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> se;
        for(int &num : nums){
            se.insert(num);
        }
        int len = 1;
        for(const int &vi :se){
            if(!se.count(vi - 1)){
                int num = vi;
                int ti = 1;
                while(se.count(num+1)){
                    ++num;
                    ++ti;
                }
                len = max(len,ti);
            }
        }
        return len;
    }
};