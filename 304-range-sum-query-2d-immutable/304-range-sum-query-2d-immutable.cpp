class NumMatrix {
public:
    
    vector<vector<int>> pre;
    NumMatrix(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        
        for(int i=0;i<n;i++)
        {
            vector<int> brr;
            
            for(int j=0;j<m;j++)
            {
                if(j==0)
                {
                    brr.push_back(matrix[i][j]);
                }
                else
                {
                    brr.push_back(matrix[i][j]+brr[j-1]);
                }
            }
            
            pre.push_back(brr);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int sum = 0;
        
        for(int i = row1; i<=row2; i++)
        {
            if(col1>0){
           int k = pre[i][col2] - pre[i][col1-1];
                sum+=k;
            }
            else
            {
                sum+=pre[i][col2];
            }
        }
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */