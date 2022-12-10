//{ Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      // Your Code Here
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
    // Your Code Here
    
        int j=n;
    
        while(j>0&&arr[j]>arr[(j-1)/2])
        {
            swap(arr[j],arr[(j-1)/2]);
            j=(j-1)/2;
        }
        
    }

    void deleteS(int arr[], int n)
    {
        int i=0;
        
        int x = arr[0];
        arr[0]=arr[n];
        
        while(i<n-1)
        {
            
            int lt = 2*i+1;
            int rt = 2*i+2;
            if(lt>=n)
            break;
            if(arr[lt]>arr[rt])
            {
                if(arr[lt]>arr[i])
                {
                    swap(arr[lt],arr[i]);
                    i=lt;
                }
                else
                break;
            }
            else if(arr[lt]<=arr[rt])
            {
                if(arr[rt]>arr[i])
                {
                    swap(arr[rt],arr[i]);
                    i=rt;
                }
                else
                break;
            }
        }
        
        arr[n]=x;
    }
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        
        for(int i=1;i<n;i++)
        {
            buildHeap(arr,i);
            // for(int j=0;j<n;j++)
            // {
            //     cout<<arr[j]<<" ";
            // }
            // cout<<endl;
        }
        
        
        
        for(int i=n-1;i>=1;i--)
        {
            deleteS(arr,i);
        }
    }
};




//{ Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends