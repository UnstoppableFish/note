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
    int sum = INT_MIN;
    int addsum(TreeNode * root){
        if(!root)return 0;
        
        int left = max(addsum(root->left),0);
        int right = max(addsum(root->right),0);
        int total = left + right + root->val;

        sum = max(sum,total);


        return root->val + max(left,right);
    }

    int maxPathSum(TreeNode* root) {
        addsum(root);
        return sum;
    }
};
