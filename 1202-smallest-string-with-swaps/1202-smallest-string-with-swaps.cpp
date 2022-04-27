class Solution {
public:
    vector<int> arr;
    vector<int> rank;
    void dsu(int n)
    {
        for(int i=0;i<n;i++){
            arr.push_back(i);
            rank.push_back(1);
        }
    }
    
    int root(int node)
    {
        if(arr[node]==node)
            return node;
        
        return arr[node]=root(arr[node]);
    }
    
    void un(int u,int v)
    {
        int x=root(u);
        int y=root(v);
        
        if(rank[x]<rank[y])
        {
            arr[x]=y;
        }
        else if(rank[x]>rank[y])
        {
            arr[y]=x;
        }
        else
        {
            arr[x]=y;
            rank[y]++;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n=s.size();
        
        dsu(n);
        
        for(int i=0;i<pairs.size();i++)
        {
            un(min(pairs[i][0],pairs[i][1]),max(pairs[i][0],pairs[i][1]));
        }
        
       
        map<int,vector<char>> mp;
        map<int,vector<int>> mp1;
        
        for(int i=1;i<=n;i++)
        {
            mp[root(i-1)].push_back(s[i-1]);
            mp1[root(i-1)].push_back(i-1);
        }
        
        for(auto &i:mp)
        {
            sort(i.second.begin(),i.second.end());
           
        }
        
        for(auto i:mp)
        {
            for(int j=0;j<i.second.size();j++)
            {
                //cout<<i.first<<" "<<mp1[i.first][j]<<" "<<mp[i.first][j]<<endl;
                s[mp1[i.first][j]]=mp[i.first][j];
            }
        }
        
        return s;
    }
};