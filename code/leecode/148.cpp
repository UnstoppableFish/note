#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
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
    ListNode* sortList(ListNode* head) {
    ListNode * cur;
    ListNode * next;
    cur = head;
    next = head->next;
    if(cur->next == NULL){
        return 
    }
    }
};