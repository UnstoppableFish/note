#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0){
            return 0;
        }
        unordered_set<char> ti;
        int right = -1;
        int len = 1;
        for(int i = 0;i < n;i++){
            if(i != 0 ){
                ti.erase(s[i - 1]);
            }
            while((right + 1) < n && !ti.count(s[right + 1])){
                ti.insert(s[right + 1]);
                ++right;
            }
            len = max(len,right - i + 1);
        }
        return len;
    }
     
};