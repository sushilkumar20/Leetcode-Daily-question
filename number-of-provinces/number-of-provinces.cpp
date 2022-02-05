class Solution {
public:
    int rank[201];
    int root[201];
    
    void dsu(int n)
    {
       for(int i=1;i<=n;i++)
       {
           rank[i]=1;
           root[i]=i;
       }
    }
    
     int find(int node)
     {
        if(root[node]==node)
            return node;
         
         return root[node]=find(root[node]);
     }
    
     void un(int u,int v)
     {
         int x=find(u);
         int y=find(v);
         
         if(rank[x]<rank[y])
         {
             root[x]=y;
         }
         else if(rank[y]<rank[x])
         {
             root[y]=x;
         }
         else
         {
             root[x]=y;
             rank[y]++;
         }
     }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        dsu(n);
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    un(i,j);
                }
            }
        }
        
        set<int> st;
        for(int i=0;i<n;i++)
        {
            st.insert(find(i));
        }
        
        return st.size();
    }
};