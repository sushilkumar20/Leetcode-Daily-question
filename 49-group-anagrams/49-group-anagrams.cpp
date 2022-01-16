class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {
            string k=strs[i];
            
            sort(k.begin(),k.end());
            
            mp[k].push_back(strs[i]);
        }
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};