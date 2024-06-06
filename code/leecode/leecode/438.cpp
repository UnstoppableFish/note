#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(m < n || n == 0){
            return {};
        }

        vector<int> scount(26);
        vector<int> pcount(26);
        vector<int> arr;

        for(int i = 0;i < n;i++){
            ++pcount[p[i] - 'a'];
            ++scount[s[i] - 'a'];
        }
        if(pcount == scount){
            arr.push_back(0);
        }

        for(int i = 0;i < m - n;i++){
            --scount[s[i] - 'a'];
            ++scount[s[i+n] - 'a'];

            if(pcount == scount){
                arr.push_back(i + 1);
        }
        }
        return arr;
    }
};