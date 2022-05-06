class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++)
        {
            if(st.size())
            {
                if(st.top().first==s[i])
                {
                    st.top().second++;
                }
                else
                {
                    st.push({s[i],1});
                }
                
                  if(st.top().second==k)
                  st.pop();
            }
            else
            {
                st.push({s[i],1});
            }
        }
        
        string ans="";
        
        while(st.size())
        {
            int x=st.top().second;
            char p=st.top().first;
            
            st.pop();
            
            for(int i=0;i<x;i++)
                ans+=p;
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};