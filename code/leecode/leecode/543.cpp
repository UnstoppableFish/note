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
    int ans;
    int seek(TreeNode * root){
        if(root == nullptr)return 0;

        int L = seek(root->left);
        int R = seek(root->right);
        ans = max(L + R + 1,ans);
        return max(L,R) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        ans = seek(root);
        return ans - 1;
    }
};