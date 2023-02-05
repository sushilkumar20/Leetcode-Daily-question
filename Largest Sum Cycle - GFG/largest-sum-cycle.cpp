//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  
  void dfs(int node,long long &ans,long long &curr,vector<int> &vis,vector<long long> &curr_tmp,vector<int>graph[])
  {
      if(curr_tmp[node])
      {
          ans = max(ans,curr-curr_tmp[node]+node);
          return;
      }
  
      curr+=node;
      curr_tmp[node]=curr;
      vis[node]+=1;
      for(auto i:graph[node])
      {
          
          if(curr_tmp[i]==0)
          {
              if(vis[i]>=2)
              continue;
              dfs(i,ans,curr,vis,curr_tmp,graph);
          }
          else
          {
              
            //   cout<<curr<<endl;
                ans = max(ans,curr-curr_tmp[i]+i);   
                curr_tmp[node]=0;
                return;
          }
      }
      
       curr-=node;
       curr_tmp[node]=0;
  }
 
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code here
    
    vector<int> graph[N];
    
    for(int i=0;i<Edge.size();i++)
    {
        if(Edge[i]!=-1){
          graph[i].push_back(Edge[i]);
            // cout<<i<<" "<<Edge[i]<<endl;
        }
    }
    
    vector<int> temp(N);
      vector<long long> curr_tmp(N);
    long long ans = -1;
   
    for(int i=0;i<N;i++)
    {
        if(temp[i]==0)
        {
            
            long long curr=0;
            dfs(i,ans,curr,temp,curr_tmp,graph);
        }
    }
    
    return ans;
  }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends