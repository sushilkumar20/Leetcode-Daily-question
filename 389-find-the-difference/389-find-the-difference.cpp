class Solution {
public:
    char findTheDifference(string s, string t) {
        
        map<char,int> mp;
        
        for(int i=0;i<s.size();i++)
            mp[s[i]]++;
        
        map<char,int> mp1;
         for(int i=0;i<t.size();i++)
            mp1[t[i]]++;
        
        for(auto i:mp1)
        {
            if(i.second!=mp[i.first])
                return i.first;
        }
        
        for(auto i:mp)
        {
            if(i.second!=mp1[i.first])
                return i.first;
        }
        
        return '-1';
    }
};