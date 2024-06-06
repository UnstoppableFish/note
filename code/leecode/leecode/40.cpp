#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> ti;
    
public:
    void bs(vector<int> & vi,int target,vector<bool> & ai,int sum,int index){
        if(sum > target)return;
        if(sum == target){
            res.push_back(ti);
            return;
        }

        for(int i = index;i < vi.size();i++){
            if(i > 0 && vi[i] == vi[i - 1] && ai[i] == false){
                continue;
            }
            ti.push_back(vi[i]);
            sum += vi[i];
            ai[i] = true;
            bs(vi,target,ai,sum,i + 1);
            sum -= vi[i];
            ai[i] = false;
            ti.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<bool> ai(candidates.size(),false);
        bs(candidates,target,ai,0,0);
        return res;
    }
};