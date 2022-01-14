class Solution {
public:
    int myAtoi(string s) {
        
        int n=s.size();
        string ans="";
        bool ok=true;
        
        int i;
        for(i=0;i<n;i++)
        {
            if(s[i]!=' ')
                break;
        }
        
        for(;i<n;i++)
        {
            if(s[i]=='-')
                ok=false;
            break;
        }
        
        if(!ok){
            i++;
            
        }
        
        if(s[i]=='+'&&ok)
            i++;
        
        
        for(;i<n;i++)
        {
            if(s[i]!='0')
                break;
        }
        for(;i<n;i++)
        {
            
            if(s[i]>='0'&&s[i]<='9')
            ans+=s[i];
            else
                break;
        }
        
        if(ans.size()==0)
            return 0;
        if(ans.size()>10)
        {
           if(!ok)
               return INT_MIN;
            
            return INT_MAX;
        }
        
        long long k=stol(ans);
        
      if(k>INT_MAX)
      {
          if(ok)
              return INT_MAX;
          return INT_MIN;
      }
        
        if(ok)
        return k;
        
        return -1*k;
        
    }
};