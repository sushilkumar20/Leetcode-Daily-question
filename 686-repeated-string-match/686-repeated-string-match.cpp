class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
        string p="";
        int cnt=0;
        while(p.size()<b.size())
        {
            p+=a;
            cnt++;
        }
        
        if(check(p,b)!=-1)
        {
            return cnt;
        }
        
        p+=a;
        cnt++;
        
         if(check(p,b)!=-1)
        {
            return cnt;
        }
        
        return -1;
    }
    
    int check(string source, string target)
    {
        if(source  == ""||target =="")
            return -1;
        
        long long d = 31;
        
        long long m = 1;
        long long mod =1e9+7;
        
        for(int i=0;i<target.size()-1;i++)
        {
            m=(m*d)%mod;
        }
        
        long long targetHash = 0;
        
        for(int i=0;i<target.size();i++)
        {
            targetHash = (targetHash*d+target[i])%mod;
        }
        
        long long hash=0;
        for(int i=0;i<target.size();i++)
        {
            hash = (hash*d+source[i])%mod;
            
        }
        
        if(hash == targetHash)
            return 0;
        
        for(int i = target.size();i<source.size();i++)
        {
            //cout<<i-target.size()<<endl;
            hash =(hash-source[i-target.size()]*m)%mod;
            
            hash = (hash*d+source[i])%mod;
            if(hash<0)
                hash+=mod;
            
           
           // cout<<hash<<" "<<targetHash<<" "<<source<<endl;
             if(hash == targetHash)
                return i-target.size()+1;
        }
        
        return -1;
    }
};