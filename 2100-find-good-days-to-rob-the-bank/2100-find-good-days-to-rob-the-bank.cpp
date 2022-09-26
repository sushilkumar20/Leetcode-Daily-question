class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        
        
        int n = security.size();
        vector<int> pref(n);
        
        pref[0] = 1;
        for(int i=1;i<n;i++)
        {
            if(security[i]<=security[i-1])
                pref[i]=pref[i-1]+1;
            else
                pref[i]=1;
        }
        
        vector<int> suff(n);
        suff[n-1] = 1;
        
        for(int i=n-2;i>=0;i--)
        {
             if(security[i]<=security[i+1])
                suff[i]=suff[i+1]+1;
            else
                suff[i]=1;
        }
        
       
        vector<int> ans;
        
         if(time==0)
        {
             for(int i=0;i<n;i++)
                 ans.push_back(i);
             
             return ans;
            
        }
        for(int i=1;i<n-1;i++)
        {
            //cout<<pref[i-1]<<" "<<suff[i+1]<<endl;
            if(pref[i-1]>=time&&suff[i+1]>=time&&security[i]<=security[i-1]&&security[i]<=security[i+1])
                ans.push_back(i);
        }
        
        return ans;
    }
};