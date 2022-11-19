class Solution {
public:
    bool isUgly(int n) {
        
        if(n<=0)
            return 0;
        for(long long i=2;i*i<=n;i++)
        {
            while(n%i==0)
            {
                if(i>5)
                    return 0;
                n=n/i;
            }
            
        }
        
        if(n>5)
            return 0;
        
        return 1;
    }
};