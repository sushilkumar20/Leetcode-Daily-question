class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.size();
        
        if(n==1)
            return 0;
        
        vector<int> pref(n);
        
        if(s[0]=='b')
            pref[0]=1;
        
        for(int i=1;i<n;i++)
        {
            if(s[i]=='b')
                pref[i] = (1+pref[i-1]);
            else
                pref[i] = pref[i-1];
        }
        
       
        
        vector<int> suff(n);
        
        if(s[n-1] == 'a')
        suff[n-1] = 1;
        
         for(int i=n-2;i>=0;i--)
         {
            if(s[i]=='a')
                suff[i]=(1+suff[i+1]);
            else
                suff[i] = suff[i+1];
         }
        
        
        int mn = n;
        
        for(int i=0;i<n;i++)
        {
           
            if(i==0)
            {
                mn=min(mn,suff[i+1]);
            }
            else if(i==n-1)
            {
                mn = min(mn,pref[i-1]);
            }
            else
            {
                mn=min(mn,pref[i-1]+suff[i+1]);
            }
            // cout<<mn<<endl;
                
        }
        
        return mn;
        
        
    }
};