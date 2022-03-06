class Solution {
public:
    int countOrders(int n) {
        
         long d=1;
        for(int i=2;i<=n;i++)
        {
            d=((2*i*i-i)*d)%1000000007;
        }
        
        return d;
    }
};