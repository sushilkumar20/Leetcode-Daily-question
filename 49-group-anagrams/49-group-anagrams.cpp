class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        map<vector<int>,vector<string>> mp;
        
        for(int i=0;i<strs.size();i++)
        {
           vector<int> arr(26,0);
            
            for(int j=0;j<strs[i].size();j++)
            {
                arr[strs[i][j]-'a']++;
            }
            
            
            
            mp[arr].push_back(strs[i]);
        }
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};