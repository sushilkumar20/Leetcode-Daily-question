class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
       int brr[3003]={0};
        
        for(int i=0;i<arr.size();i++)
        {
           brr[arr[i]]++;
        }
        int count=0;
        int ans=0;
        for(int i=1;i<3003;i++)
        {
            if(brr[i]==0)
              count++;
            if(count==k)
            {
                ans=i;
                break;
            }
        }
        return ans;
        
    }
};