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
        if(i==s.size())
           { 
            ans.push_back(curr);
            return;
           } 
        //cout<<i<<endl;
        
        for(int j=i;j<s.size();j++)
        {
            if(isPalindrome(s.substr(i,j-i+1)))
            {
                curr.push_back(s.substr(i,j-i+1));
                help(j+1,ans,curr,s);
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