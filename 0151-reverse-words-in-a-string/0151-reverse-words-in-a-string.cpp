class Solution {
public:
    string reverseWords(string s) {
        
        vector<string> ans;
        
        string ss="";
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(ss.size()!=0)
                    ans.push_back(ss);
                ss="";
            }
            else
            {
                ss+=s[i];
            }
        }
        
        if(ss.size()!=0)
            ans.push_back(ss);
        
        ss="";
        
        for(int i=ans.size()-1;i>=0;i--)
        {
            ss+=ans[i];
            ss+=" ";
        }
        
        return ss.substr(0,ss.size()-1);
    }
};