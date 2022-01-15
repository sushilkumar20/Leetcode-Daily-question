class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n=arr.size();
        vector<int> edge[n];
        
        if(arr.size()==1)
            return 0;
     
        
        map<int,vector<int>> mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        
        int step=0;
        
        queue<int>q;
        q.push(0);
        
        while(q.size()>0)
        {
            step++;
            int p=q.size();
            
            for(int i=0;i<p;i++)
            {
                int j=q.front();
                q.pop();
                
                if(j-1>=0&&mp.find(arr[j-1])!=mp.end())
                {
                    q.push(j-1);
                }
                 if(j+1<n&&mp.find(arr[j+1])!=mp.end())
                {
                    if(j+1==n-1)
                        return step;
                    q.push(j+1);
                }
               
                    if(mp.find(arr[j])!=mp.end())
                    {
                        for(auto k:mp[arr[j]])
                        {
                            if(k!=j)
                            {
                                if(k==n-1)
                                {
                                    return step;
                                }
                                q.push(k);
                            }
                        }
                    }
                
                if(mp.find(arr[j])!=mp.end())
                mp.erase(arr[j]);
                
            }
        }
        
        return step;
        
        
        
    }
};