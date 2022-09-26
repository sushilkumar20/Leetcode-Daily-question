class Solution {
public:
    
    int fdPar(int u, vector<int>&par)
    {
        if(par[u]==u)
            return u;
            
        return par[u] = fdPar(par[u],par);
    }
    
    void un(int u, int v, vector<int> &par, vector<int>&rank)
    {
        int x = par[u];
        int y = par[v];
        
        if(rank[x]<rank[y])
        {
            par[x] = y;
        }
        else if(par[y]<par[x])
        {
            par[y] = x;
        }
        else
        {
            par[y]=x;
            rank[x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        
        vector<int> par(26);
        vector<int> rank(26);
        
        for(int i=0;i<26;i++)
        {
            par[i]=i;
            rank[i]=0;
        }
        
        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
            {
                int u = equations[i][0]-'a';
                int v = equations[i][3]-'a';
                
                un(u,v,par,rank);
            }
        }
        
        
         for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
            {
                int u = equations[i][0]-'a';
                int v = equations[i][3]-'a';
                
               int x = fdPar(u,par);
                int y = fdPar(v,par);
                
                //cout<<x<<" "<<y<<endl;
                if(x==y)
                    return false;
            }
        }
        
        return true;
    }
};