class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0;
        
        for(int j=0;j<t.size();j++)
        {
            if(i==s.size())
                break;
            if(s[i]==t[j])
                i++;
        }
        
         if(i==s.size())
             return true;
        
        return false;
    }
};