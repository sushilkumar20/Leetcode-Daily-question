class Solution {
public:
    bool isPalindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            
            i++;
            j--;
        }
        
        return true;
    }
    
    void help(int i, vector<vector<string>> &ans, vector<string> &curr, string s)
    {
        if(s.size()==0)
           { 
            ans.push_back(curr);
            return;
           } 
       // cout<<s<<endl;
        
        for(int j=0;j<s.size();j++)
        {
            if(isPalindrome(s.substr(0,j+1)))
            {
                curr.push_back(s.substr(0,j+1));
                help(i,ans,curr,s.substr(j+1));
                curr.pop_back();
            }
        }
        
        
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> curr;
        help(0,ans,curr,s);
        
        return ans;
        
    }
    
    
};