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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int up = 0;
        int down = m - 1 ;
        int left = 0;
        int right = n - 1;

        vector<int> ti;
        while(true){
            for(int i = left;i <= right;i++) ti.push_back(matrix[up][i]);
            if(down < ++up) break;
            for(int i = up;i <= down;i++) ti.push_back(matrix[i][right]);
            if(left> --right) break;
            for(int i = right;i >= left;i--) ti.push_back(matrix[down][i]);
            if (up > --down) break;
            for(int i = down;i >= up;--i) ti.push_back(matrix[i][left]);
            if(++left> right) break; 
        }
        return ti;
    }
}; 