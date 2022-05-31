class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n = s.size();
        if(n<k)
            return false;
        map<int,int>mp;
        
        int p = 0;
        
        for(int i=0;i<k;i++)
        {
            p=(p<<1)|(int)(s[i]-'0');
        }
        
        mp[p]++;
        
        int  q = (1<<(k-1));
        
        for(int i=k;i<n;i++)
        {
            if((p&q) != 0)
            {
               p=(p^q); 
            }
            
            p = ((p<<1)|(int)(s[i]-'0'));
            mp[p]++;
        }
        
        
        int l = (1<<k);
        
        
        for(int i=0;i<l;i++)
        {
            if(mp[i]==0)
                return false;
        }
        
        return true;
    }
};