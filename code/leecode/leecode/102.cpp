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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)return {};
        vector<vector<int>> ti;
        vector<int> vi;
        queue<TreeNode*> ai;
        ai.push(root);
        while(!ai.empty()){
            int a = ai.size();
            for(int i = 0;i < a;i++){
                TreeNode * temp = ai.front();
                ai.pop();
                vi.push_back(temp->val);
                if(temp->left)ai.push(temp->left);
                if(temp->right)ai.push(temp->right);
            }
            ti.push_back(vi);
            vi.clear();
        }
        return ti;
    }
};