class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<pair<char,int>> st;
        
        int ans=0;
        int cnt=0;
        for(int i=0; i<s.size();i++)
        {
            if(s[i]=='(')
                cnt++;
            else
            {
                cnt --;
                
                if (s[i-1]=='(')
                {
                    ans += (1<<cnt);
                }
            }
        }
        
        return ans;
    }
};