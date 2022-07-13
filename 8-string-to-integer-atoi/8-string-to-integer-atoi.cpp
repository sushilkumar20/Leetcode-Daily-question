class Solution {
public:
    int myAtoi(string s) {
        
        string ans="";
        bool ok=true;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                ans+=s[i];
            }
            else if(s[i]=='-'||s[i]=='+'){
                 if(ans.size()>0)
                    break; 
                cnt++;
                if(s[i]=='-')
                ok=false;
                
               
            
            }
            else if(s[i]!=' ')
                break;
            else if(s[i] == ' ')
            {
                if(ans.size()>0||cnt>0)
                    break;
            }
        }
        if(cnt>=2)
            return 0;
        int i=0;
        for(;i<ans.size();i++)
        {
            if(ans[i]!='0')
                break;
        }
        
        ans=ans.substr(i);
        
        //cout<<ans<<" "<<ok<<endl;
      
        if(ok)
        {
          //  cout<<ans<<endl;
            long long k =0;
            int cnt=0;
            for(int i=ans.size()-1;i>=0;i--)
            {
                k+=((long long)pow(10ll,cnt)*(long long)(ans[i]-'0'));
               // cout<<k<<endl;
                 if(k>=INT_MAX||cnt>=10)
                 return INT_MAX; 
                cnt++;
            }
            
           
            
            return k;
        }
        else
        {
             long long k =0;
            int cnt=0;
            for(int i=ans.size()-1;i>=0;i--)
            {
                k-=((long long)pow(10,cnt)*(ans[i]-'0'));
              //  cout<<k<<endl;
                if(k<=INT_MIN||cnt>=10)
                return INT_MIN;
                cnt++;
            }
           // cout<<k<<endl;
            // k=-1*k;
            
            
            return k;
        }
        
    }
};