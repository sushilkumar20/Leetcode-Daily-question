class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st1;
        //https://leetcode.com/problems/backspace-string-compare/
        for(int i=0;i<s.size();i++)
        {
            if(st1.size()&&st1.top()!='#'&&s[i]=='#')
                st1.pop();
            else{
                if(s[i]!='#')
                st1.push(s[i]);
            }
        }
        
        string s1="";
        
        while(st1.size())
        {
            s1+=st1.top();
            st1.pop();
        }
        
        reverse(s1.begin(),s1.end());
        
         stack<char> st2;
        
        for(int i=0;i<t.size();i++)
        {
            if(st2.size()&&st2.top()!='#'&&t[i]=='#')
                st2.pop();
            else{
                if(t[i]!='#')
                st2.push(t[i]);
            }
        }
        
        string s2="";
        
        while(st2.size())
        {
            s2+=st2.top();
            st2.pop();
        }
        
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};