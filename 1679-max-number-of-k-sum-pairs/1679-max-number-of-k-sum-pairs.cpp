class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        map<int,int> mp;
        
        int n=nums.size();
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        int cnt=0;
        for(auto i:mp)
        {
            int p = k - i.first;
            
            if(mp.find(p)==mp.end())
                continue;
            
            if(p!=i.first)
            cnt+=min(mp[p],mp[i.first]);
            else{
                cnt+=mp[p]/2;
               // cout<<mp[p]<<endl;
            }
            
            
            mp[p]=0;
            mp[i.first]=0;
            
        }
        
        return cnt;
    }
};