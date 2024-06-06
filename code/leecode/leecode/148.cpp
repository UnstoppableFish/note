#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr)return nullptr;
        vector<int> ti;
        ListNode * cur = head;
        while(cur != nullptr){
            ti.push_back(cur->val);
            cur = cur->next;
        }
        sort(ti.begin(),ti.end());
        ListNode * node = head;
        int n = ti.size();
        for(int i = 0;i < n;i++){
            node->val = ti[i];
            node = node->next;
        }
        return head;
    }
};
