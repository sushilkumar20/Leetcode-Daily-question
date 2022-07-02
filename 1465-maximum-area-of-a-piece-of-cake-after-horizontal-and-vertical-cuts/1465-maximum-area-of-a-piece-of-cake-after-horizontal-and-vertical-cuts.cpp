class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalcuts, vector<int>& verticalcuts) {
        
       sort( horizontalcuts.begin(),horizontalcuts.end());
        sort( verticalcuts.begin(), verticalcuts.end());
        int n=horizontalcuts.size();
        long long k=horizontalcuts[0];
        for(int i=1;i<horizontalcuts.size();i++)
        {
            if(k<(horizontalcuts[i]-horizontalcuts[i-1]))
                k=(horizontalcuts[i]-horizontalcuts[i-1]);
           
        }
        if(k<(h-horizontalcuts[n-1]))
            k=(h-horizontalcuts[n-1]);
       
        
        long long a=verticalcuts[0];
        int m=verticalcuts.size();
        
        for(int i=1;i<verticalcuts.size();i++)
        {
            if(a<(verticalcuts[i]-verticalcuts[i-1]))
            a=verticalcuts[i]-verticalcuts[i-1];
        }
        if(a<(w-verticalcuts[m-1]))
        a=w-verticalcuts[m-1];
                  
       return (int)(a%1000000007*k%1000000007)%1000000007;
        
    }
};