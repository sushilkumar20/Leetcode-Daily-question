//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
    //   vector<long long> arr(n);
       
    //   for(int i=0;i<n;i++)
    //   {
          
    //       arr[i] = 
           
           
    //   }
       
    //   for(int i=0;i<n;i++)
    //   arr.push_back(arr[i]);
       
       int lw = -1;
       int sum=0;
       
       for(int i=0;i<2*n;i++)
       {
           sum+=p[i%n].petrol-p[i%n].distance;
        //   cout<<sum<<endl;
           if(sum<0)
           {
               lw=i;
               sum=0;
           }
           else
           {
               if(i-lw>=n)
               return lw+1;
           }
       }
       
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends