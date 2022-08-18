class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int> mp;
        
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        
        priority_queue<int> pq;
        
        for(auto j:mp)
            pq.push(j.second);
        
        int cnt=0;
        
        int n= arr.size();
        int t = n/2;
        
        while(n>t&&pq.size())
        {
            n-=pq.top();
            pq.pop();
            cnt++;
        }
        
        return cnt;
    }
};