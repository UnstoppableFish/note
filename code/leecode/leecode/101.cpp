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
    bool charge(TreeNode * u,TreeNode * v){
        queue<TreeNode*> ti;
        ti.push(u);
        ti.push(v);
        while(!ti.empty()){
            u = ti.front();ti.pop();
            v = ti.front();ti.pop();

            if(!u && !v)continue;
            if(!u || !v)return false;
            if(u->val != v->val)return false;

            ti.push(u->left);
            ti.push(v->right);

            ti.push(u->right);
            ti.push(v->left);
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return charge(root,root);
    }
};
