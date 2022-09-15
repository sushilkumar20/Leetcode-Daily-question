class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> mp;
        
        
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        
        unordered_map<int,int> mp1 = mp;
        
        set<int> arrk;
        
        for(int i=0;i<nums.size();i++)
        {
           int diff = abs(nums[i]-nums[0]);
          //  cout<<diff<<endl;
            if(diff!=0&&diff%2==0)
            {
                arrk.insert(diff/2);
            }
        }
        
        while(arrk.size())
        {
            int k = *arrk.begin();
            arrk.erase(arrk.begin());
            
            
            vector<int> arr1;
            bool ok=true;
            for(int i=0;i<n;i++)
            {
                if(mp.find(nums[i])==mp.end())
                    continue;
                if(mp.find(nums[i]+2*k)!=mp.end())
                {
                    arr1.push_back(nums[i]+k);
                    mp[nums[i]]--;
                    mp[nums[i]+2*k]--;
                    
                    if(mp[nums[i]]==0)
                        mp.erase(nums[i]);
                     if(mp[nums[i]+2*k]==0)
                        mp.erase(nums[i]+2*k);
                }
                else
                {
                    //cout<<nums[i]<<endl;
                    ok=false;
                    break;
                }
            }
            
            if(ok)
                return arr1;
            
            mp=mp1;
        }
            
        
        return {};
    }
};