class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int left=0;
        int right  =0;
        
        int mx=0;
        
        map<char,int> mp;
        while(right<s.size())
        {
            if(mp.find(s[right])!=mp.end())
            {
                left = max(mp[s[right]],left);
            }
            
            mx=max(mx,right-left+1);
            mp[s[right]] = right+1;
            
            right++;
        }
        
        return mx;
    }
};