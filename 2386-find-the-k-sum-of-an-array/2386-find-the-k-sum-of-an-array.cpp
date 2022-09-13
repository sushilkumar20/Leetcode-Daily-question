class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        int n=nums.size();
        long long mxSum=0;
        
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                mxSum+=nums[i];
            else
                nums[i] = -1*nums[i];
        }
        
        if(k==1)
            return mxSum;
        // mxSum - kth smallest number == ans;
        
        sort(nums.begin(),nums.end());
        
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        pq.push({nums[0],0});
        
        while(k>1)
        {
            long long sum = pq.top().first;
            int lstInd = pq.top().second;
            k--;
            
            pq.pop();
           long long res = mxSum-sum;
            
            if(k==1)
                return res;
            
            if(lstInd+1<n)
            {
                pq.push({sum-nums[lstInd]+nums[lstInd+1],lstInd+1});
                pq.push({sum+nums[lstInd+1],lstInd+1});
            }
            
        }
        
        return -1;
    }
};