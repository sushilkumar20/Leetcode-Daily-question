class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        
        int n = changed.size();
        sort(changed.begin(),changed.end());
        
        vector<int> ans;
        
        map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp.find(changed[i])==mp.end())
                continue;
            if(mp.find(changed[i]*2)!=mp.end())
            {
                if(changed[i]==0&&mp[changed[i]]<2)
                {
                    return{};
                }
                mp[changed[i]]--;
                ans.push_back(changed[i]);
                mp[changed[i]*2]--;
                
                if(mp[changed[i]*2]==0)
                    mp.erase(changed[i]*2);
                if(mp[changed[i]]==0)
                    mp.erase(changed[i]);
            }
            else 
            {
                return {};
            }
        }
        
        return ans;
    }
};