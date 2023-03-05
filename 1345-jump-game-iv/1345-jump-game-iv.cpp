class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[arr[i]].push_back(i);
            
        }
        
        vector<int> vis(n);
        
        queue<int> q;
        
        q.push(0);
        if(n-1==0)
            return 0;
        vis[0]=1;
        int tm = 1;
        while(q.size())
        {
            int sz = q.size();
            
            for(int i=0;i<sz;i++)
            {
                int x = q.front();
                
              
                q.pop();
                
                if(x-1>=0&&vis[x-1]==0)
                {
                    if(x-1  == n-1)
                        return tm;
                    
                    vis[x-1]=1;
                   q.push(x-1);
                }
                
                 if(x+1<n&&vis[x+1]==0)
                {
                     if(x+1  == n-1)
                        return tm;
                     vis[x+1]=1;
                    q.push(x+1);
                }
                
                for(auto j:mp[arr[x]])
                {
                    if(i!=j)
                    {
                        if(vis[j]==0)
                        {
                            if(j  == n-1)
                            return tm;
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                }
                
                 mp.erase(arr[x]);
            }
            
            tm++;
        }
        
        return -1;
    }
};