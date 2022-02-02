class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        if(p.size()>s.size())
            return ans;
        vector<int> brr(26,0);
        int k=p.size();
        
        for(int i=0;i<p.size();i++)
        {
            brr[(int)(p[i]-'a')]++;
        }
         
        vector<int>crr(26,0);
        for(int i=0;i<p.size();i++)
        {
            crr[(int)(s[i]-'a')]++;
        }
        
        bool ok=true;
        for(int i=0;i<26;i++)
        {
            if(brr[i]!=crr[i])
            {
                ok=false;
                break;
            }
        }
        
        if(ok)
            ans.push_back(0);
        
        for(int i=1;i<=s.size()-p.size();i++)
        {
            crr[(int)(s[i-1]-'a')]--;
            
             crr[(int)(s[i+k-1]-'a')]++;
            
            bool ok=true;
        for(int i=0;i<26;i++)
        {
            if(brr[i]!=crr[i])
            {
                ok=false;
                break;
            }
        }
        
        if(ok)
            ans.push_back(i);
        }
        
        
        return ans;
    }
};