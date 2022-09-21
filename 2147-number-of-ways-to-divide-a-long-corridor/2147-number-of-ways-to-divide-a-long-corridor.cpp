class Solution {
public:
    int numberOfWays(string corridor) {
        
        int mod = 1e9+7;
        
        vector<long long> arr;
        
        for(int i=0;i<corridor.size();i++)
        {
            if(corridor[i] == 'S')
                arr.push_back(i);
        }
        
        if(arr.size()==0)
            return 0;
        
        if(arr.size()%2)
            return 0;
        
        long long ans = 1;
        for(int i=2;i<arr.size();i+=2)
        {
            ans = (ans*(arr[i]-arr[i-1]))%mod;
           
        }
        
        return ans;
    }
};