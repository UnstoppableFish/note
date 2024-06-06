#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;



class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        for(Node *ti = head;ti != nullptr;ti = ti->next->next){
            Node * vi = new Node(ti->val);
            vi->next = ti->next;
            ti->next = vi;
        }

        for(Node * ti = head;ti != nullptr;ti = ti->next->next){
            Node * nownode = ti->next;
            if(ti->random == nullptr){
                ti->next->random = nullptr;
                continue;
            }
            nownode->random = ti->random->next;
        }
        Node * st = head->next;
        for(Node * ti = head;ti != nullptr;ti = ti->next->next){
            Node * newnode = ti->next;
            ti->next = newnode->next;
            newnode->next = (newnode->next != nullptr) ? newnode->next->next : nullptr;
            
        }
        return st;
    }
};