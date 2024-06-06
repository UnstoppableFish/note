#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    unordered_map <int,int> ti;
    int addum(TreeNode * root,long long sum,int targetsum){
        if(!root)return 0;
        int i = 0;
        sum += root->val;
        if(ti.count(sum - targetsum)){
            i = ti[sum - targetsum];
        }
        ++ti[sum];
        i += addum(root->left,sum,targetsum);
        i += addum(root->right,sum,targetsum);
        --ti[sum];
        return i;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root->val > 100000)return 0;
        if(!root)return 0;
        ti[0] = 1;
        return addum(root,0,targetSum);
    }
};
