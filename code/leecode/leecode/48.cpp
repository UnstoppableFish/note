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
    void rotate(vector<vector<int>>& matrix) {
        auto ti = matrix;
        int n = matrix.size();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                ti[j][n - 1 - i] = matrix[i][j];
            }
        }
        matrix = ti;
    }
};