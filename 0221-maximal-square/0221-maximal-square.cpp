class Solution {
public:
    void calculateMax(vector<int>&height,int &mx)
    {
        int n = height.size();
        vector<int> nextSm(n,n);
        vector<int> prvSm(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(st.size()&&height[i]<height[st.top()]){
                nextSm[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        while(st.size())
            st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()&&height[i]<height[st.top()]){
                prvSm[st.top()]=i;
                st.pop();
            }
            
            st.push(i);
        }
        
        
        int mx1 = 0;
        
        for(int i=0;i<n;i++)
        {
            // cout<<height[i]<<" ";
            int width = abs(nextSm[i]-prvSm[i]-1);
            int d = min(width,height[i]);
           
            mx1=max(mx1,d*d);
        }
        
//         cout<<endl;
//         for(int i=0;i<n;i++)
//         {
//             cout<<nextSm[i]<<" "<<prvSm[i]<<endl;
//         }
       
//         cout<<mx1<<endl;
        
        mx=max(mx,mx1);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int mx = 0;
        
        vector<int> height(m,0);
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                if(matrix[i][j]=='0')
                    height[j]=0;
                else
                    height[j]++;
            }
            
            calculateMax(height,mx);
        }
        
        return mx;
    }
};