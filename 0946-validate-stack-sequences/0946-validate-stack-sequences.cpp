class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        
        int j = 0;
        for(int i=0;i<pushed.size();i++)
        {
            st.push(pushed[i]);
            
            while(st.size()&&st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        
        // cout<<j<<endl;
        
        while(j<popped.size())
        {
            if(st.size() == 0)
                return 0;
            if(st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            else
            {
                return 0;
            }
        }
        
        return 1;
    }
};