class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]!=0)
                {
                    if(i-1>=0)
                    matrix[i][j] += matrix[i-1][j];
                }
            }
        }
        
        for(int i=0;i<n;i++)
        {
            sort(matrix[i].rbegin(),matrix[i].rend());
        }
        
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                //cout<<matrix[i][j]<<" ";
                mx=max(mx,(j+1)*matrix[i][j]);
            }
           // cout<<endl;
        }
        
        return mx;
    }
};