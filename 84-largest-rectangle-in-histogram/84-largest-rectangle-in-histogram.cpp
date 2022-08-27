class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n=heights.size();
        vector<int> leftSmall(n);
        vector<int> rightSmall(n);
        
        stack<int> st;
        
        for(int i=0;i<heights.size();i++)
        {
            while(st.size()&&heights[i]<heights[st.top()])
            {
                rightSmall[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
        {
            rightSmall[st.top()]=n;
            st.pop();
        }
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()&&heights[i]<heights[st.top()])
            {
                leftSmall[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
          while(st.size())
            {
                leftSmall[st.top()]=-1;
                st.pop();
            }
        
        int mx =0;
        
        for(int i=0;i<n;i++)
        {
            int width = rightSmall[i] - leftSmall[i]-1;
            
            //cout<<leftSmall[i]<<" "<<rightSmall[i]<<endl;
            mx=max(mx,heights[i]*width);
        }
        
        return mx;
    }
};