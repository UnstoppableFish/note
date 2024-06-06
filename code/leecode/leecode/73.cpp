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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row,col;
        for(int i = 0;i < n;i++){
            if(!matrix[0][i]){
                row = 1;
            }
        }
        for(int i = 0;i < m;i++){
            if(!matrix[i][0]){
                col = 1;
            }
        }

        for(int i = 1;i< m;i++){
            for(int j = 1;j < n;j++){
                if(!matrix[i][j]){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                if(!matrix[0][j] || !matrix[i][0]){
                    matrix[i][j] == 0;
                }
            }
        }

        for(int i = 0;i < n;i++){
            if(row){
                matrix[0][i] = 0;
            }
        }

        for(int i = 0;i < m;i++){
            if(col){
                matrix[i][0] = 0;
            }
        }
    }
};