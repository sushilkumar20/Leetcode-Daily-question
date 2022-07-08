class Solution {
public:
    void findSmallerToLeft(vector<int>&height, vector<int>&to_left)
    {
         int n = height.size();
        stack<int> st;
        
        for(int i= n-1;i>=0;i--)
        {
            while(st.size()&& height[i]<height[st.top()])
            {
                to_left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(st.size())
        {
            to_left[st.top()] =-1;
            st.pop();
        }
    }
    
       void findSmallerToRight(vector<int>&height, vector<int>&to_right)
     {
           int n = height.size();
          stack<int> st;
        
        for(int i= 0;i<n;i++)
        {
            while(st.size()&& height[i]<height[st.top()])
            {
                to_right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while(st.size())
        {
            to_right[st.top()] = n;
            st.pop();
        }
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j]+=1;
            }
            
            
            
            vector<int> to_left(m,0);
            vector<int> to_right(m,0);
            
            findSmallerToLeft(height,to_left);
            findSmallerToRight(height, to_right);
            
            for(int i=0;i<m;i++)
            {
                int h = height[i];
                int width = to_right[i] - to_left[i]-1;
                
                mx=max(mx,h*width);
            }
        }
        
        return mx;
    }
};