class Solution {
    public:
    int longestPalindrome(string s) {
        int count [128]={0};
        for (auto c:s)
            count[c]++;

        int ans = 0;
        for (int i=0;i<128;i++) {
            ans += (count[i] / 2) * 2;
          
        }
        
        if(ans!=s.size())
            ans++;
        return ans;
    }
};
