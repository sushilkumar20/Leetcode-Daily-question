class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    
        vector<vector<int>>arr;
        
        for(int i=0;i<mat.size();i++)
        {
            int sum=0;
            vector<int> a;
            for(int j=0;j<mat[i].size();j++)
            {
                sum+=mat[i][j];
            }
            a.push_back(sum);
            a.push_back(i);
            arr.push_back(a);
        }
        
        sort(arr.begin(),arr.end());
        
        vector<int> ans;
        
        for(int i=0;i<k;i++)
        {
            ans.push_back(arr[i][1]);
        }
        
        return ans;
    }
};