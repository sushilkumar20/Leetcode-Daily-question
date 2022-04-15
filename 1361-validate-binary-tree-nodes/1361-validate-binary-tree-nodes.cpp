class Solution {
public:
    
    int findParent(int x,vector<int>&par,vector<int>&rank)
    {
        if(par[x]==x)
            return x;
        
        return par[x] = findParent(par[x],par,rank);
    }
    
    void Union(int x,int y,vector<int>&par,vector<int>&rank)
    {
        int p = findParent(x,par,rank);
        int q = findParent(y,par,rank);
        
        if(rank[p]>rank[q])
        {
            par[q]=p;
        }
        else if(rank[p]<rank[q])
        {
            par[p]=q;
        }
        else
        {
            par[p]=q;
            rank[p]++;
        }
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
     
        
      vector<int> par(n);
        vector<int> rank(n);
        
        for(int i=0;i<n;i++)
        {
            par[i]=i;
            rank[i]=1;
        }
        
        vector<int> father(n,0);
        
        for (int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
            {
                Union(i,leftChild[i],par,rank);
                father[leftChild[i]]++;
            }
            if(rightChild[i]!=-1)
            {
                 Union(i,rightChild[i],par,rank);
                father[rightChild[i]]++;
            }
        }
        int oneParent=0;
        for(int i=0;i<n;i++)
        {
            if(father[i]==1)
                oneParent++;
        }
        
        int noComponent=0;
        
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                noComponent++;
        }
        
        if(oneParent!=n-1||noComponent>1)
            return false;
        return true;
        
    }
};