class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        int x=arr.size();
       
        int n=(1<<x);
        //cout<<n<<endl;
        int mx=0;
         vector<int> brr(26);
        string s="";
        for(int i=0;i<=n;i++)
        {
           
            
            for(int j=0;j<arr.size();j++)
            {
                if((i&(1<<j))!=0)
                {
                    s+=arr[j];
                    if(s.size()>26)
                        break;
                }
                
                
            }
            
            //cout<<s<<endl;
            
           
            bool ok=true;
            for(int j=0;j<s.size();j++)
            {
                brr[s[j]-'a']++;
                if(brr[s[j]-'a']>1)
                {
                    ok=false;
                    break;
                }
            }
            
            if(ok)
                mx=max(mx,(int)s.size());
            
            s="";
            
            for(int i=0;i<26;i++)
                brr[i]=0;
        }
        
        return mx;
    }
};