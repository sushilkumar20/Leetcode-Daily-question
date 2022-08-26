class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<32;i++)
        {
            int x = (1<<i);
            int p=x;
            vector<int> arr(10,0);
            mp[x] = arr;
            while(p>0)
            {
                mp[x][p%10]++;
                p=p/10;
            }
        }
        
        vector<int> brr(10);
        
        while(n>0)
        {
            brr[n%10]++;
            n=n/10;
        }
        for(auto i:mp)
        {
            if(i.second==brr)
                return true;
        }
        
        return false;
        
    }
};