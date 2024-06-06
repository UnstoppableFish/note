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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * dummy = new ListNode(-1);
        ListNode * cur = dummy;
        ListNode * ti = list1;
        ListNode * vi = list2;
        while(ti != nullptr && vi != nullptr){
            if(ti->val <= vi->val){
                cur->next = ti;
                ti = ti->next;
            }
            else{
                cur->next = vi;
                vi = vi->next;
            }
            cur = cur->next;
        }
        
        cur->next = (ti == nullptr) ? vi : ti;
        return dummy->next;
    }
};