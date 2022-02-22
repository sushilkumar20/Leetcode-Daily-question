class Solution {
public:
    int titleToNumber(string s) {
        
        reverse(s.begin(),s.end());
        
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(i==0)
            {
                ans+=(int)(s[i]-'A')+1;
            }
            else
            {
                ans+=(int)pow(26,i)*((int)(s[i]-'A')+1);
            }
        }
        
        return ans;
    }
};