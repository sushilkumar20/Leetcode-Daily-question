class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
         for(int i=0;i<arr.size();i++)
        {
            arr[i]=arr[i]%k;
        }
        map<int,int> mp;
       for(int i=0;i<arr.size();i++)
       {
        mp[(arr[i]+k)%k]++;   
       }
        if(mp[0]%2!=0)return false;
        for(int i=1;i<k;i++)
        {
            if(mp[i]!=mp[k-i])
                return false;
        }
        return true;
    }
};