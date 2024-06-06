#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(string &s : strs){
            string key = s;
            sort(key.begin(),key.end());
            map[key].emplace_back(s);
        }
        vector<vector<string>> ans;
        for(auto it = map.begin();it != map.end();it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
int main(){
    vector<string> a;
    Solution so;
    a.emplace_back("ate");
    a.emplace_back("tae");
    a.emplace_back("mam");
    int n = a.size();
    vector<vector<string>> as;
    as = so.groupAnagrams(a);
    for(const auto &row : as){
        for(const auto &col : row){
            cout << col << "";
        }
    }

    return 0;
}
