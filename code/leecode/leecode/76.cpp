#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n){
            return "";
        }
        unordered_map<char,int> ti;
        for(char & c:t){
            ++ti[c];
        }
        int c = t.size();
        int len = 0;
        int minlen = 0;
        int begin = 0;
        for(int l = 0,r = 0;r < n;r++){
            if(ti[s[r]] > 0){ 
                --c;
            }
            --ti[s[r]];
            if(c == 0){
                while(ti[s[l]] < 0){
                    ++ti[s[l]];
                    ++l;
                }
                len = r - l + 1;
                
                if(len < minlen || minlen == 0){
                    minlen = len;
                    begin = l;
                }
                ++ti[s[l]];
                ++l;
                ++c;
            }
        }
        return s.substr(begin,minlen);
    }
};