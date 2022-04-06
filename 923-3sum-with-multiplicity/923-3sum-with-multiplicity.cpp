class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        
       const int mod= 1e9+7;
       
        int ans=0;
        for(int i=0;i<arr.size()-1;i++)
        {
             int count[101]={0};
            for(int j=i+1;j<arr.size();j++)
            {
               int k=target-arr[i]-arr[j];
               if(k>=0&&k<=100&&count[k]>0)
               {
                   ans=(ans%mod+count[k]%mod)%mod;
               }
                count[arr[j]]++;
            }
        }
        
        return ans;
        
        
    }
};