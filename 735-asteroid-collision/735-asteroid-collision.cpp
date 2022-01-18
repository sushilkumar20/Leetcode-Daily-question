class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        
        stack<int> st;
        
        int size=a.size();
        
        for(int i=0;i<size;i++)
        {
            bool ok=true;
            while(st.size()>0&&st.top()>0&&a[i]<0)
            {
                if(st.top()<abs(a[i]))
                    st.pop();
                else if(st.top()==abs(a[i]))
                {
                    ok=false;
                    st.pop();
                    break;
                }
                else
                {
                    ok=false;
                    break;
                }
            }
            
            if(ok)
                st.push(a[i]);
            
            
        }
        
        vector<int> ans;
        
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};