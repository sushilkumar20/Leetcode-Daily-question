class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> mp;
        
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        
        int cnt=0;
        
        for(auto i:mp)
            cnt+=2*(i.second/2);
        
        if(cnt!=s.size())
            return cnt+1;
        
        return cnt;
    }
};