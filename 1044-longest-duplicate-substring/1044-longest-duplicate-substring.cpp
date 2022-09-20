class Solution {
public:
    
    int pos(string s, int sz, string &ans)
    {
        unsigned long long base = 131;
        
        unsigned long long mod = 1e9+7;
        
        unsigned long long  y =  sz-1;
        unsigned long long  x = 131;
       unsigned  long long k=1;
        
        set<long long> st;
        
        while(y>0)
        {
            if(y%2==0)
            {
                x=(x*x);
                y=y/2;
            }
            else
            {
                k=(k*x);
                y--;
            }
        }
        
        long long hash = 0;
        
        for(int i=0;i<sz;i++)
        {
            hash = (hash*base+(s[i]-'a'));
        }
        
        st.insert(hash);
        for(int i=sz;i<s.size();i++)
        {
           
                hash = (hash-(s[i-sz]-'a')*k);
                hash = (hash*base+(s[i]-'a'));
            
            if(st.find(hash)!=st.end())
            {
                
                
                return i-sz+1;
            }
            
           
                st.insert(hash);
        }
        
        return -1;
        
    }
    string longestDupSubstring(string s) {
        
        int low = 0;
        int high = s.size();
        string ans="";
        int mx = 0;
        while(low<=high)
        {
            
            int mid = (low+high)/2;
            
            if(pos(s,mid,ans)!=-1)
            {
                mx=mid;
                low=mid+1;
            }
            else
                high = mid-1;
        }
        
        if(mx==0)
            return "";
        //cout<<mx<<endl;
        ans = s.substr(pos(s,mx,ans),mx);
        return ans;
    }
};