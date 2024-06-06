#include<vector>
#include<stdio.h>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        unordered_map<string,vector<string>> ma;
        for(string &i:strs){
            string key = i;
            sort(i.begin(),i.end());
            ma[i].emplace_back(key);
        }
        vector<vector<string>> ot;
        for(auto ti = ma.begin();ti != ma.end();ti++){
            ot.emplace_back(ti->second);
        }
        return ot;
    }
};