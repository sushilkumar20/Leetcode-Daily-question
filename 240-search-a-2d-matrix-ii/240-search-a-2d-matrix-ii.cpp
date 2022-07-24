class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i=0;i<matrix.size();i++)
        {
            int k = lower_bound(matrix[i].begin(),matrix[i].end(),target)-matrix[i].begin();
            
           // cout<<k<<endl;
            if(k<matrix[i].size()&&k>=0&&matrix[i][k]==target)
                return true;
        }
        
        return false;
    }
};