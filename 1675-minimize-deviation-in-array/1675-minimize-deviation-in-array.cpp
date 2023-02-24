class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       
       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
       
        int n = nums.size();
        
        int mx = 0;
        for(int i=0;i<n;i++)
        {
            int k = nums[i];
            
            while(k%2==0)
            {
                k=k/2;
            }
            
           if(nums[i]%2)
           {
               pq.push({nums[i],2*nums[i]});
           }
            else
            {
                pq.push({k,nums[i]});
            }
            
            mx = max(mx,k);
        }
        
        int ans = INT_MAX;
        
        while(1)
        {
            auto y = pq.top();
            pq.pop();
            
            // cout<<mx-y[0]<<endl;
            ans = min(ans,mx-y.first);
            
            if(y.first == y.second)
                break;
            
            mx = max(mx,2*y.first);
            
            pq.push({2*y.first,y.second});
        }
        
        return ans;
        
        
    }
};