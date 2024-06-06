#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return {};
        }
        vector<int> ti(n);
        ti[0] = 1;
        for(int i = 1;i < n;i++){
            ti[i] = ti[i - 1] * nums[i - 1];
        }

        vector<int> vi(n);
        vi[n - 1] = 1;
        for(int i = n - 2;i >= 0;i--){
            vi[i] = vi[i + 1] * nums[i + 1];
        }

        vector<int> ai(n);
        for(int i = 0;i < n;i++){
            ai[i] = ti[i] * vi[i];
        }
        return ai;
    }
};




