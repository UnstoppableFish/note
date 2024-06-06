#include <iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

void rev(string &s){
    int i = 0;
    int j = s.size() - 1;
    while(i < j){
        swap(s[i],s[j]);
        i++;j--;
    }
}

int main() {
    string ti;
    vector<char> vi;
    string st;
    char a;
    stack<char> ai;
    cin >> ti;
    for(int i = 0;i < ti.size();i++){
        if(!ai.empty() && ai.top() == ti[i]){
            ai.pop();
            continue;
        }
        ai.push(ti[i]);
    }
    while(!ai.empty()){
        st += ai.top();
        ai.pop();
    }
    rev(st);
    if(st.empty()){
        cout << 0;
    }else{
        cout << st;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")