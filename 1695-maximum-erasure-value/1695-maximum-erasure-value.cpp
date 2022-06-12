class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> pref(n);
        map<int,int> mp;
        int left =-1;
        int mx =nums[0];
        pref[0] = nums[0];
        mp[nums[0]] =0 ;
         for(int i=1;i<n;i++)
         {
             pref[i] = pref[i-1]+nums[i];
             
             if(mp.find(nums[i])!=mp.end())
             {
                // cout<<nums[i]<<endl;
                 left = max(left,mp[nums[i]]);
                // cout<<left<<endl;
             }
             
             if(left>=0)
             mx = max(mx, pref[i]-pref[left]);
             else
             mx = max(mx, pref[i]);  
             mp[nums[i]] =i;
         }
        
        return mx;
    }
};