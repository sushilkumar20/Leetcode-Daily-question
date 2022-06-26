// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        if(n>m) return kthElement(nums2,nums1,m,n,k);
        
       
        int low = max(0,k-m), high = min(k,n);
        
        while(low<=high)
        {
            int mid = (low+high)/2;
            
            int cut1 = mid;
            int cut2 = k-mid;
            
            int left1 = INT_MIN;
            int left2 = INT_MIN;
            int right1 = INT_MAX;
            int right2 = INT_MAX;
            
            if(cut1>0)
            left1 = nums1[cut1-1];
            
            if(cut2>0)
            left2 = nums2[cut2-1];
            
            if(cut1<n)
            right1 = nums1[cut1];
            
            if(cut2<m)
            right2 = nums2[cut2];
            
            if(left1<=right2&&left2<=right1)
            return max(left1,left2);
            else if(left1>right2)
            {
                high=mid-1;
            }
            else
            low = mid+1;
        }
        
        return 0;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends