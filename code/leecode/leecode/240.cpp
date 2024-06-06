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
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        while(i < n){
            if(matrix[0][i] > target && i < n){
                break;
            }
            ++i;
        }
        
        int j = 0;
        while(j < m){
            if(matrix[j][0] > target && j < m){
                break;
            }
            ++j;
        }
        

        for(int a = 0;a < j;a++){
            auto it = lower_bound(matrix[a].begin(),matrix[a].begin() + i - 1,target);
            if(*it == target){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<vector<int>> ti;
    ti.push_back({1,1});
    s.searchMatrix(ti,2);
    return 0;
}