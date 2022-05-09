class Solution {
public:
    
    void help(int i,string &s1,int j, string &s2,string &s,vector<string>&ans)
    {
        
        if(s.size()==2*s1.size())
        {
            ans.push_back(s);
            return;
        }
        
        if(i<s1.size()){
        s+=s1[i];
        
        help(i+1,s1,j,s2,s,ans);
        s.pop_back();
        }
        
        if(j<i&&j<s2.size()){
        s+=s2[j];
        help(i,s1,j+1,s2,s,ans);
        s.pop_back();
        }
        
        
        
    }
    vector<string> generateParenthesis(int n) {
        
        string s1="";
        string s2="";
        
        for(int i=0;i<n;i++){
            s1+='(';
            s2+=")";
        }
        
        int i=0;
        int j=0;
        
        string s="";
        
        vector<string> ans;
        help(i,s1,j,s2,s,ans);
        
        return ans;
    }
};