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
//     ListNode *detectCycle(ListNode *head) {
//         if(head == nullptr){
//             return nullptr;
//         }

//         unordered_set<ListNode *> ti;
//         while(head != nullptr){
//             if(ti.count(head)){
//                 return head;
//             }
//             ti.insert(head);
//             head = head->next;

//         }
//         return nullptr;
//     }
// };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr){
            return nullptr;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        while(true){
            if(fast->next == nullptr || fast == nullptr){
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)break;
        }
        fast = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            
        }
        return fast;
    }
};