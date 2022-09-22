class Solution {
public:
    string reverseWords(string s) {
        
         int n=s.size();
       
        
        string ans="";
        string k="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(k.size()>0)
                {
                    reverse(k.begin(),k.end());
                    ans+=k;
                    ans+=" ";
                }
                k="";
            }
            else
            {
                k+=s[i];
            }
        }
               if(k.size()>0)
                {
                    reverse(k.begin(),k.end());
                    ans+=k;
                   
                }
        
        return ans;
    }
};