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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temp = headA;
        unordered_set<ListNode *> ti;
        while(temp != nullptr){
            ti.insert(temp);
            temp = temp->next;
        }

        ListNode * a = headB;
        while(a != nullptr){
            if(ti.count(a)){
                return a;
            }
            a = a->next;
        }
        return nullptr;
    }
};