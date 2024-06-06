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
    bool isPalindrome(ListNode* head) {
        vector<int> ti;
        ListNode * cur = head;
        while(cur != nullptr){
            ti.push_back(cur->val);
            cur = cur->next;
        }
        int i = 0;
        int j = ti.size() - 1;
        while(i < j){
            if(ti[i] != ti[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
};