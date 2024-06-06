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

// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root == nullptr)return;
//         return max(maxDepth(root->left),maxDepth(root->right)) + 1;
//     }
// };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)return 0;
        queue<TreeNode*> ti;
        ti.push(root);
        int sum = 0;
        while(!ti.empty()){
            int i = ti.size();
            while(i > 0){
                TreeNode * temp = ti.front();
                ti.pop();
                if(temp->left)ti.push(temp->left);
                if(temp->right)ti.push(temp->right);
                --i;
            }
            ++sum;
        }
        return sum;
    }
};