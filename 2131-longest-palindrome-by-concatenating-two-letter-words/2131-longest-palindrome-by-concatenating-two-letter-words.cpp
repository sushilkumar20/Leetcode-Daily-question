class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        map<string,int> mp;
        
        for(auto i:words)
            mp[i]++;
        
        int cnt=0;
        bool ok = 0;
        for(auto i:mp)
        {
            string x= i.first;
            string y= x;
            
            reverse(y.begin(),y.end());
            
            if(x==y)
            {
                if(mp[x]%2&&ok)
                {
                    mp[x]--;
                }
                cnt+=2*mp[x];
                if(mp[x]%2)
                ok=1;
            }
            else
            {
                cnt+=4*min(mp[x],mp[y]);
                mp[x]=0;
                mp[y]=0;
            }
            
        }
        
        return cnt;
    }
};