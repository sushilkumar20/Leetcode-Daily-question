class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
       vector<int> arr2(26);
        
        for(int i=0;i<words2.size();i++)
        {
            vector<int> temp(26,0);
            for(auto j:words2[i])
                temp[j-'a']++;
            
            for(int j=0;j<26;j++)
            {
                if(temp[j]>arr2[j])
                    arr2[j] = temp[j];
            }
        }
        
        vector<string> ans;
        
        for(int i=0;i<words1.size();i++)
        {
            vector<int> arr1(26,0);
            for(auto j:words1[i])
                arr1[j-'a']++;
            
            bool ok = true;
            
            for(int j=0;j<26;j++)
            {
                if(arr1[j]<arr2[j])
                {
                    ok=false;
                        break;
                }
            }
            
            if(ok)
                ans.push_back(words1[i]);
        }
        
        return ans;
    }
};