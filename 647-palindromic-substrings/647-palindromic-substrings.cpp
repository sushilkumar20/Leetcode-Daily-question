class Solution {
public:
    int countSubstrings(string s) {
        
        int count=0;
        for(int i=0;i<s.size();i++)
        {
            string k="";
            for(int j=i;j<s.size();j++)
            {
                k+=s[j];
                
                int a=0;
                int b=k.size()-1;
                bool ok=true;
                while(b>a)
                {
                    if(k[a]!=k[b])
                    {
                        ok=false;
                        break;
                    }
                    a++;
                    b--;
                }
                //cout<<k<<endl;
                if(ok)
                    count++;
            }
        }
        
        
        return count;
    }
};