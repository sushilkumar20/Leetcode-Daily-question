class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int n = strs.size();
        sort(strs.begin(),strs.end());
        
        string ans="";
        
        int i=0;
        
        string first = strs[0];
        string last = strs[n-1];
        
        for(;i<min(first.size(),last.size());i++)
        {
            if(first[i]==last[i])
                ans+=first[i];
            else
                break;
        }
        
        
        return ans;
    }
};