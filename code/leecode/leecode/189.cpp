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
    void reverse(vector<int> & ti,int l,int r){
        while(l < r){
            swap(ti[l],ti[r]);
            ++l;
            --r;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0){
            return;
        }
        
        reverse(nums,0,n - 1);
        reverse(nums,0,k - 1);
        reverse(nums,k,n - 1);
        
    }
};