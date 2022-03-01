class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int> ans(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            int k=i;
            
           
            while(k!=0)
            {
                if((k&1)!=0)
                {
                    ans[i]++;
                }
                k=k/2;
                
            }
        }
        
      
        
        return ans;
    }
};