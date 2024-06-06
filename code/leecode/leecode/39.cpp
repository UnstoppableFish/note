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
    void bs(vector<int> & vi,int target,int sum,int index){
        if(sum > target)return;
        if(sum == target){
            res.push_back(ti);
            return;
        }

        for(int i = index;i < vi.size();i++){
            ti.push_back(vi[i]);
            sum += vi[i];
            bs(vi,target,sum,i);
            sum -= vi[i];
            ti.pop_back();

        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        bs(candidates,target,0,0);
        return res;
    }
};
