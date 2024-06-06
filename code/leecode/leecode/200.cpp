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
    bool inarea(vector<vector<char>> &ti,int r,int c){
        return r >= 0 && r < ti.size() && c >= 0 && c < ti[0].size();
    }

    void dfs(vector<vector<char>> & ti,int r,int c){
        if(!inarea(ti,r,c))return;

        if(ti[r][c] != '1')return;

        ti[r][c] = '2';

        dfs(ti,r - 1,c);
        dfs(ti,r + 1,c);
        dfs(ti,r,c - 1);
        dfs(ti,r,c + 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int sum = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    ++sum;
                }
            }
        }
        return sum;
    }
};