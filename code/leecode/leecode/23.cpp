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
    ListNode * addin(ListNode* ti,ListNode * vi){
        ListNode * dummy = new ListNode(0);
        ListNode * pre = dummy;
        while(ti != nullptr && vi != nullptr){
            if(ti->val < vi->val){
                pre->next = ti;
                ti = ti->next;
            }
            else{
                pre->next = vi;
                vi = vi->next;
            }
            pre = pre->next;
        }
        pre->next = (ti == nullptr) ? vi : ti;
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * vi = nullptr;
        for(int i = 0;i < lists.size();i++){
            vi = addin(lists[i],vi);
        }
        return vi;
    }
};
