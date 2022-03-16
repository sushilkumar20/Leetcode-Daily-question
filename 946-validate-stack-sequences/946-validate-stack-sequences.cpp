class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int j=0;
        for(int i=0;i<pushed.size();i++)
        {
            while(j<popped.size()&&st.size()&&st.top()==popped[j])
            {
                st.pop();
                j++;
            }
            st.push(pushed[i]);
            
        }
        
        while(j<popped.size()&&st.size()&&st.top()==popped[j])
        {
            st.pop();
            j++;
        }
        if(st.size())
            return false;
        
        return true;
    }
};