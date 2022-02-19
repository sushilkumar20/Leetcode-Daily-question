class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        int mx=0;
        for(int i=0;i<nums.size();i++)
        {
            int k=nums[i];
            
            while(k%2==0)
            {
                k=k/2;
            }
            
            if(nums[i]%2==0)
            pq.push({k,nums[i]});
            else
                pq.push({k,2*nums[i]});
            
            mx=max(mx,k);
        }
        
        int ans=INT_MAX;;
        
        while(1)
        {
            auto it=pq.top();
            pq.pop();
            
            ans=min(ans,mx-it.first);
            
            if(it.first==it.second)
                break;
            
            mx=max(mx,2*it.first);
            
            pq.push({it.first*2,it.second});
        }
        
        return ans;
        
    }
};