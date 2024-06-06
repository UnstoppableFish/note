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
    unordered_map<int,int>ti;
    TreeNode * createtree(vector<int>& preorder, vector<int>& inorder,int pre_l,int pre_r,int in_l,int in_r){
        if(pre_l > pre_r)return nullptr;
        int pre_root = preorder[pre_l];
        int in_root_i = ti[pre_root];

        TreeNode * root = new TreeNode(pre_root);

        int left_size = in_root_i - in_l;

        root->left = createtree(preorder,inorder, pre_l + 1, pre_l + left_size, in_l, in_root_i - 1);
        root->right = createtree(preorder,inorder, pre_l + 1 + left_size, pre_r, in_root_i + 1, in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0;i < n;i++){
            ti[inorder[i]] = i;
        }
        return createtree(preorder,inorder,0,n-1,0,n-1);
    }
};