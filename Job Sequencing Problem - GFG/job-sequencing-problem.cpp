// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


 // } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
   static bool cmp(Job A, Job B)
    {
        return A.profit>B.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
        int t =0;
        
        for(int i=0;i<n;i++)
        {
            t=max(t,arr[i].dead);
        }
        
        vector<int> tim(t);
        
        sort(arr,arr+n,cmp);
        
        int ans =0;
        int cnt =0;
        for(int i=0;i<n;i++)
        {
            //cout<<arr[i].profit<<endl;
            int dead = arr[i].dead;
            
            dead--;
            
            while(dead>=0)
            {
                if(tim[dead]==0)
                {
                    ans += arr[i].profit;
                    tim[dead] = arr[i].id;
                    cnt++;
                    break;
                }
                
                dead--;
            }
        }
        
        return vector<int>{cnt, ans};
    } 
};

// { Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}


  // } Driver Code Ends