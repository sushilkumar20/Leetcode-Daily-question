class Solution {
public:
    int maxLength(vector<string>& arr) {
        
        int x=arr.size();
       
        int n=(1<<x);
        //cout<<n<<endl;
        int mx=0;
        for(int i=0;i<=n;i++)
        {
           
            string s="";
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
            
            vector<int> brr(26);
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
        }
        
        return mx;
    }
};