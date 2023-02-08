//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      
      vector<long long> ans;
      vector<int> st1(n+1);
       vector<int> st2(n+1);
       
      long long total = n*n;
      int cnt = 0;
      int n1=0;
      int n2=0;
      for(int i = 0;i<arr.size();i++)
      {
          int cnt = 0;
          if(st1[arr[i][0]]==0)
          {
              total-=n;
            //   st1.insert(arr[i][0]);
              
              if(st2[arr[i][1]]==0)
              cnt++;
              
              total += n2;
          }
          
          if(st2[arr[i][1]]==0)
          {
              total-=n;
               
               if(st1[arr[i][0]]==0)
               cnt++;
               total += n1;
               
          }
          if(st1[arr[i][0]]==0)
          n1++;
          if(st2[arr[i][1]]==0)
          n2++;
          st1[arr[i][0]]=1;
          st2[arr[i][1]] = 1;
          
        //   st1.insert(arr[i][0]);
        //   st2.insert(arr[i][1]);
          
          if(cnt)
          total+=1;
          
          ans.push_back(total);
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends