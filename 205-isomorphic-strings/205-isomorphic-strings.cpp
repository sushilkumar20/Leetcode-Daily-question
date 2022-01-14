class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
         map<char,char> mp;
        map<char,char> mp1;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==NULL&&mp1[t[i]]==NULL)
            {
                //cout<<1<<endl;
                mp[s[i]]=t[i];
                mp1[t[i]]=s[i];
               // mp[t[i]]=s[i];
            }
            else
            {
                if(mp[s[i]]!=t[i]||mp1[t[i]]!=s[i]){
                   // cout<<mp[t[i]]<<endl;
                    return false;
                }
            }
        }
        
        return true;
    }
};