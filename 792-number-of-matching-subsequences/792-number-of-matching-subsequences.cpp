#include<bits/stdc++.h>

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        
       vector<vector<int>> mp(26);
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]-'a'].push_back(i);
        }
        
        int ans=0;
        bool found=true;
        int prev;
       for(auto& word : words) {
            bool found = true;
            
            for(int i = 0, prev = -1; found && i < size(word); i++) {
                auto& v = mp[word[i]-'a'];
                auto it = upper_bound(begin(v), end(v), prev); 
                if(it == end(v)) found = false;                  // doesn't exist
                else prev = *it;                                 // update prev for next check
            }
            ans += found;
        }
        
        return ans;
        
    }
};