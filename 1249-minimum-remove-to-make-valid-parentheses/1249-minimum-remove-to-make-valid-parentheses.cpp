class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<pair<char,int>> st;
        
        for(int i=0;i<s.size();i++)
        {
            if(st.size()&&st.top().first=='('&&s[i]==')')
                st.pop();
            else
            {
                if(s[i]==')'||s[i]=='(')
                    st.push({s[i],i});
            }
        }
        
        string ans="";
        map<int,char> mp;
        while(st.size())
        {
            mp[st.top().second] = st.top().first;
            st.pop();
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(i)!=mp.end())
                continue;
            
            ans+=s[i];
        }
        
        return ans;
        
    }
};