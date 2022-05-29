class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n);
        
        for(int i=0;i<n;i++)
        {
            while(st.size()&&temperatures[st.top()]<temperatures[i])
            {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
        {
            ans[st.top()] = 0;
            st.pop();
        }
        
        return ans;
    }
};