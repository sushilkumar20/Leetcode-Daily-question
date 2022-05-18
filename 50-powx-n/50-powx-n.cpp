class Solution {
public:
    double myPow(double x, int n) {
        
        double ans =1;
        
        bool ok = true;
        
        if(n<0)
        {
            x=1.0/x;
        }
        
       long long y  = abs((long long)n);
        while(y>0)
        {
           
            if(y%2)
            {
                ans = ans*x;
                y--;
            }
            else
            {
                x = x*x;
                y=y/2;
            }
        }
        
       
        return ans;
    }
};