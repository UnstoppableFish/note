#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

class Trie {
private:
    bool isend ;
    Trie * next[26];
public:
    Trie() {
        isend = false;
        memset(next, 0, sizeof(next));
    }
    
    void insert(string word) {
        Trie *node = this;
        for(char & i : word){
            if(node->next[i - 'a'] == nullptr){
                node->next[i - 'a'] = new Trie;
            }
            node = node->next[i - 'a'];
        }
        node->isend = true;
    }
    
    bool search(string word) {
        Trie * node = this;
        for(char & i : word){
            if(node->next[i - 'a'] == nullptr){
                return false;
            }
            node = node->next[i - 'a'];
        }
        return node->isend;
    }
    
    bool startsWith(string prefix) {
        Trie * node = this;
        for(char & i : prefix){
            if(node->next[i - 'a'] == nullptr){
                return false;
            }
            node = node->next[i - 'a'];
        }
        return true;
    }
};