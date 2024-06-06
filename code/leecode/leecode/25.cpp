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
    ListNode *turna(ListNode *head){
        ListNode *pre = nullptr;
        ListNode * cur = head;
        while(cur != nullptr){
            ListNode * next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next; 
        }
        return pre;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr)return nullptr;
        ListNode *dummy = new ListNode(0,nullptr);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * end = pre;
        while(end != nullptr){
            for(int i = 0;i < k && end != nullptr;i++)end = end->next;
            if(end == nullptr)break;
            ListNode * start = pre->next;
            ListNode * next = end->next;
            end->next = nullptr;

            pre->next = turna(start);
            start->next = next;
            pre = start;
            end = pre;
        }
        return dummy->next;
    }
};
