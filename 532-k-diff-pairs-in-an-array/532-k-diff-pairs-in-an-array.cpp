class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        
        int ans=0;
        
        for(auto i:mp)
        {
            int x=i.first;
           // cout<<x<<endl;
            if(k==0){  
                if(mp[x]>1)
                ans++;
                continue;
            }
            
            if(mp.find(x+k)!=mp.end())
            {
                //cout<<x<<" "<<mp[x+1]<<" "<<mp[x]<<endl;
               
                ans++;
            }
        }
        
        return ans;
        
    }
};