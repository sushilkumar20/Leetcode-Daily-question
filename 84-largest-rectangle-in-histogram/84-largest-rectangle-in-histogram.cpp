class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int mx=0;
        int size=heights.size();
        stack<int> st;
        
        vector<int> to_right(size,-1);
        for(int i=0;i<size;i++)
        {
            while(st.size()&&heights[st.top()]>heights[i])
            {
                to_right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
        while(st.size())
        {
            to_right[st.top()]=size;
            st.pop();
        }
        
        vector<int> to_left(size,-1);
        
        for(int i=size-1;i>=0;i--)
        {
            while(st.size()&&heights[st.top()]>heights[i])
            {
                to_left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        
         while(st.size())
        {
            to_left[st.top()]=-1;
            st.pop();
        }
        
        to_left[0]=-1;
        to_right[size-1]=size;
        for(int i=0;i<size;i++)
        {
            //cout<<to_right[i]<<" "<<to_left[i]<<endl;
            mx=max(mx,heights[i]*(to_right[i]-to_left[i]-1));
        }
        return mx;
    }
};