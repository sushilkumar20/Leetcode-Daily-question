class Solution {
public:
    void findGreaterToLeft(vector<int>&heights, vector<int> &greaterElementLeft)
    {
        int n = heights.size();
        stack<int> st;
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()&&heights[i]<heights[st.top()])
            {
                greaterElementLeft[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
        {
            greaterElementLeft[st.top()] = -1;
            st.pop();
        }
    }
    
    void findGreaterToRight(vector<int> &heights, vector<int> &greaterElementRight)
    {
        int n = heights.size();
        stack<int> st;
        
        for(int i=0;i<n;i++)
        {
            while(st.size() && heights[i]<heights[st.top()])
            {
                greaterElementRight[st.top()] = i;
                st.pop();
            }
            
            st.push(i);
        }
        
         while(st.size())
         {
            greaterElementRight[st.top()] = n;
            st.pop();
         }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        vector<int> greaterElementLeft(n);
        
        vector<int> greaterElementRight(n);
        
        findGreaterToLeft(heights,greaterElementLeft);
        findGreaterToRight(heights, greaterElementRight);
        
        int mx = 0;
        
        
        for(int i=0;i<n;i++)
        {
            int h = heights[i];
           
            int width = greaterElementRight[i] - greaterElementLeft[i]-1;
            
            //cout<<h<<" "<<width<<endl;
            mx = max(mx,h*width);
        }
        
        return mx;
    }
};