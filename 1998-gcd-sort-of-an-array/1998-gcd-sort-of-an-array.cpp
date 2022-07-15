class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    void dsu()
    {
        for(int i=0;i<=1e5+50;i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    
     int findParent(int u)
    {
        if(parent[u]==u)
            return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    void unionD(int x, int y)
    {
        int u = findParent(x);
        int v = findParent(y);
        if(rank[u]>rank[v])
        {
            parent[v] = u;
        }
        else if(rank[v]>rank[u])
        {
            parent[v] = u;
        }
        else
        {
            parent[u] = v;
            rank[v]++;
        }
    }
    
   
    
    
    bool gcdSort(vector<int>& nums) {
        
       // map<int,vector<int>> mp;
        
        int n=nums.size();
        dsu();
        for(int i=0;i<nums.size();i++)
        {
            int k=nums[i];
            
            bool ok=false;;
            while(k%2==0)
            {
                k=k/2;
                ok=true;
            }
            
            if(ok)
            {
                unionD(2,nums[i]);
            }
            
            for(int j=3;j<=sqrt(k);j+=2)
            {
                ok=false;
                
                while(k%j==0)
                {
                    k=k/j;
                    ok=true;
                }
                
                if(ok)
                {
                    unionD(j,nums[i]);
                    //unionD(i,j);
                    //cout<<parent[j]<<" "<<j<<" "<<i<<endl;
                }
            }
            
            if(k>2)
            {
                unionD(k,nums[i]);
                //unionD(i,k);
                //cout<<parent[k]<<" "<<k<<" "<<i<<endl;
            }
        }
        
        
        map<int,vector<int>> index;
        map<int,vector<int>> value;
        
        for(int i=0;i<n;i++)
        {
            int par = findParent(nums[i]); 
           // cout<<par<<endl;
            index[par].push_back(i);
            value[par].push_back(nums[i]);
        }
        
        vector<int> brr(n);
        int cnt=0;
        for(auto &i:value)
        {
            sort(i.second.begin(),i.second.end());
            cnt++;
            for(int j=0;j<i.second.size();j++)
            {
                brr[index[i.first][j]]=i.second[j];
                //cout<<i.second[j]<<" "<<index[i.first][j]<<" "<<cnt<<endl;
            }
        }
        
        
        sort(nums.begin(),nums.end());
        
       // cout<<brr.size()<<endl;
        if(nums==brr)
            return true;
        
        return false;
    }
};