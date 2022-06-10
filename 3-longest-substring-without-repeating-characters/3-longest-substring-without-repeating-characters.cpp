class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n = s.size();
        int left = 0;
        int right = 0;
        map<char,int> mp;
        int mx =0;
        while(right<n)
        {
            if(mp.find(s[right])!=mp.end())
            {
                left = max(left,mp[s[right]]);
            }
            
            mx = max(mx,right-left+1);
            mp[s[right]] = right+1;
            right++;
        }
        
        return mx;
    }
};