class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        
       
        
        stack<int> st;
        
        int n=t.size();
         vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            while(st.size()&&t[st.top()]<t[i])
            {
                ans[st.top()]=(i-st.top());
                st.pop();
            }
            st.push(i);
        }
        
        while(st.size())
        {
               ans[st.top()]=0;
                st.pop();
        }
        
        return ans;
    }
};