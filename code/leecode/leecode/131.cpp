#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> path;
    string ai;
public:
    bool ishui(string & s,int i,int j ){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;--j;
        }
        return true;
    }
    void bs(string &s,int index){
        if(index == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = index;i < s.size();i++){
            if(ishui(s,index,i)){
                path.push_back(s.substr(index,i - index + 1));
            }else{
                continue;
            }
            bs(s,i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        bs(s,0);
        return res;
    }
};