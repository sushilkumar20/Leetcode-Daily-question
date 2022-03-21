class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        int n=s.size();
        vector<vector<int>> arr(26,vector<int>(2,-1));
        
        for(int i=0;i<n;i++)
        {
            int k=s[i]-'a';
            
            if(arr[k][0]==-1)
            {
                arr[k][0]=i;
                
            }
            arr[k][1]=i;
        }
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> brr;
        
        int end=0;
        int st=0;
        for(int i=0;i<26;i++)
        {
            if(arr[i][0]==-1)
                continue;
            
            if(arr[i][0]>end)
            {
                brr.push_back({st,end});
                st=arr[i][0];
                end=arr[i][1];
            }
            else
            {
                end=max(arr[i][1],end);
            }
        }
        
        brr.push_back({st,end});
        
        for(int i=0;i<brr.size();i++)
            ans.push_back(brr[i][1]-brr[i][0]+1);
        
        return ans;
        
    }
};