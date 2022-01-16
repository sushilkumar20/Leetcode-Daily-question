class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        
        map<string,vector<string>> mp;
        vector<int> arr(26,0);
        for(int i=0;i<strs.size();i++)
        {
           fill(arr.begin(),arr.end(),0);
            
            for(int j=0;j<strs[i].size();j++)
            {
                arr[strs[i][j]-'a']++;
            }
            
            string key="";
            
            for(int i=0;i<26;i++)
            {
                key+="#";
                key+=(char)(arr[i]-'0');
            }
            
            
            mp[key].push_back(strs[i]);
            
        }
        
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};