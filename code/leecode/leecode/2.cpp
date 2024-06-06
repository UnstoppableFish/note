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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr;
        ListNode * tail = nullptr;
        int  ci = 0;
        while(l1 != nullptr || l2 != nullptr){
            int m = 0;
            int n = 0;
            if(l1 != nullptr) m = l1->val;
            if(l2 != nullptr) n = l2->val;
            int sum = m + n + ci;

            if(head == nullptr){
                head = tail = new ListNode(sum % 10);
            }
            else{
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            ci = sum / 10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(ci > 0){
            tail->next = new ListNode(ci);
            tail = tail->next;
        }
        return head;

    }
};
