class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        map<string,vector<string>> mp;
        
        for(int i=0;i<bank.size();i++)
        {
            for(int j=0;j<bank.size();j++)
            {
                if(i==j)
                    continue;
                
                int diff =0;
                
                for(int k=0;k<bank[i].size();k++)
                {
                    if(bank[i][k]!=bank[j][k])
                        diff++;
                }
                
                if(diff==1)
                mp[bank[i]].push_back(bank[j]);
            }
            
            int  diff=0;
            for(int k=0;k<bank[i].size();k++)
                {
                    if(bank[i][k]!=startGene[k])
                        diff++;
                }
                
            if(diff==1)
            mp[startGene].push_back(bank[i]);
            
            
        }
        
        queue<string> q;
        q.push(startGene);
        
        int level = 0;
        
        if(startGene==endGene)
            return level;
        map<string,int> vis;
        vis[startGene]=1;
        while(q.size())
        {
            level++;
            int n = q.size();
            for(int j=0;j<n;j++)
            {
                string par = q.front();
                q.pop();


                for(auto i:mp[par])
                {
                    if(i==endGene)
                        return level;
                    if(vis[i]==0){
                        q.push(i);
                        vis[i]=1;
                    }
                }
            }

        }
        
        return -1;
        
        
    }
};