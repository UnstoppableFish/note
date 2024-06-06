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
//     void coss(vector<int>& ti,TreeNode * vi){
//         if(vi == nullptr)return;

//         coss(ti,vi->left);
//         ti.push_back(vi->val);
//         coss(ti,vi->right);
//     }
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root == nullptr)return{};

//         vector<int> ti;
//         coss(ti,root);
//         return ti;
//     }
// };

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         stack<TreeNode*> vi;
//         vector<int> ti;
//         TreeNode * cur = root;
//         while(cur != nullptr || !vi.empty()){
//             while(cur != nullptr){
//                 vi.push(cur);
//                 cur = cur->left;
//             }
//             cur = vi.top();
//             ti.push_back(cur->val);
//             vi.pop();
//             cur = cur->right;
//         }
//         return ti;
//     }
// };


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode * cur = nullptr;
        vector<int> ti;
        while(root != nullptr){
            if(root->left != nullptr){
                cur = root->left;
                while(cur->right != nullptr){
                    cur = cur->right;
                }
                cur->right = root;
                TreeNode * temp = root;
                root = root->left;
                temp->left = nullptr;
            }else{
                ti.push_back(root->val);
                root = root->right;
            }
        }
        return ti;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)return {};
        vector<int> ti;
        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode * cur = root->left;
                while(cur->right != nullptr){
                    cur = cur->right;
                }
                cur->right = root;
                TreeNode * temp = root;
                root = root->left;
                temp->left = nullptr;
            }else{
                ti.push_back(root->val);
                root = root->right;
            }
        }
        return ti;
    }
};