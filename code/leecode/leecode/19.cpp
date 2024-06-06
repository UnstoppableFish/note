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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode * ti = head;
//         int i = 0;
//         while(ti != nullptr){
//             ti = ti->next;
//             ++i;
//         }
//         if(i - n == 0){
//             return head->next;
//         }
//         ListNode * vi = head;
//         int j = 0;
//         while(j != (i - n - 1)){
//             vi = vi->next;
//             ++j;
//         }
//         if(vi->next->next == nullptr){
//             vi->next = nullptr;
//         }
//         else{
//             vi->next = vi->next->next;
//         }
        
//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * ti = head;
        stack<ListNode *> vi;
        while(ti != nullptr){
            vi.push(ti);
            ti = ti->next;
        }
        int i = 0;
        while(i != n){
            vi.pop();
            ++i;
        }
        if(vi.empty() && i <= 1){
            return nullptr;
        }
        if(vi.empty() && i > 1){
            return head->next;
        }
        ListNode * ai = vi.top();
        ai->next = ai->next->next;
        return head;
    }
};
