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
    vector<string> res;
    string ti = "";
    vector<string> ai = {{},{},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
    void backtrace(const string &digits,int index){
        if(ti.length() == digits.length()){
            res.push_back(ti);
            return;
        }
        int a = digits[index] - '0';
        string st = ai[a];
        for(int i = index;i < st.size();i++){
            ti.push_back(st[i]);
            backtrace(digits,index + 1);
            ti.pop_back();
        }
    }

public:

    vector<string> letterCombinations(string digits) {
        if(digits == "")return {};
        backtrace(digits,0);
        return res;
    }
};