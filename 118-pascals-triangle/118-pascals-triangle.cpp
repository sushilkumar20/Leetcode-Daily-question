class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
          vector<vector<int>> ans;
        
        for(int i=0;i<numRows;i++)
        {
            vector<int> arr;
             arr.push_back(1);
            if(i==0)
            {
               
                ans.push_back(arr);
                continue;
            }
            for(int j=1;j<=i-1;j++)
            {
                arr.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            
            arr.push_back(1);
            
            ans.push_back(arr);
            
        }
        
        return ans;
    }
};