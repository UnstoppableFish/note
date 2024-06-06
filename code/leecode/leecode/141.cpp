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
    bool hasCycle(ListNode *head) {
        if(head == nullptr){
            return false;
        }

        unordered_set<ListNode *> ti;
        ListNode * cur = head;
        while(head != nullptr){
            if(ti.count(cur)){
                return true;
            }
            ti.insert(cur);
            cur = cur->next;
        }
        return false;
    }
};
