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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)return head;
        ListNode * dummy = new ListNode(0,nullptr);
        dummy->next = head;
        ListNode * pre = dummy;
        ListNode * cur = head;
        while(cur != nullptr && cur->next != nullptr){
            ListNode * next = cur->next;
            ListNode * sk = next->next;

            next->next = cur;
            pre->next = next;
            cur->next = sk;

            pre = cur;
            cur = sk;
        }
        return dummy->next;
    }
};
