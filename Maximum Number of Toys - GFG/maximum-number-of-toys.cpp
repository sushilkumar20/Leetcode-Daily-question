//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
      
      vector<int> arr = A;
      
      sort(arr.begin(),arr.end());
      
      vector<long long> prf(N);
      
      prf[0]=arr[0];
      
      for(int i=1;i<N;i++)
      prf[i] = prf[i-1]+arr[i];
      
      vector<int> ans;
      
      for(int i=0;i<Q;i++)
      {
          long long sm =  Queries[i][0];
          
          int cnt = upper_bound(prf.begin(),prf.end(),sm)-prf.begin();
          
          cnt--;
          
          int cnt1 = 0;
          
          sort(Queries[i].begin()+2,Queries[i].end());
          
          vector<int> brr;
          for(int j=2;j<Queries[i].size();j++)
          {
              brr.push_back(A[Queries[i][j]-1]);
          }
          
          
          sort(brr.begin(),brr.end());
          
          for(int j=0;j<brr.size();j++)
          {
              
              int x = brr[j];
            //   cout<<x<<" kk "<<j<<endl;
              int k = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
              
              if(k<arr.size())
              {
                  if(k<=cnt)
                  {
                      sm += x;
                      cnt = upper_bound(prf.begin(),prf.end(),sm)-prf.begin();
                      cnt--;
                      cnt1++;
                  }
                //   else
                //   break;
              }
          }
          
        //   cout<<cnt<<" "<<cnt1<<endl;
          if(cnt>=0)
          ans.push_back(cnt+1-cnt1);
          else
          ans.push_back(0);
      }
      
      return ans;
  }
};

//{ Driver Code Starts.
int main() {
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    int N;
    cin>>N;
    vector<int>A(N);
    for(auto &i:A){
      cin>>i;
    }
    int Q;
    cin>>Q;
    vector<vector<int>> Queries(Q);
    for(int i=0;i<Q;i++){
      int x,y;
      cin>>x>>y;
      Queries[i].push_back(x);
      Queries[i].push_back(y);
      for(int j=0;j<Queries[i][1];j++){
        cin>>x;
        Queries[i].push_back(x);
      }
    }
    Solution obj;
    auto ans =obj.maximumToys(N,A,Q,Queries);
    for(auto i:ans)
      cout<<i<<" ";
    cout<<endl;
 }
}
// } Driver Code Ends