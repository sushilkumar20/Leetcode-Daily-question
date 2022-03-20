class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
       int arr[6]={0};
       int brr[6]={0};
        
        for(int i=0;i<A.size();i++)
        {
            arr[A[i]-1]++;
            brr[B[i]-1]++;
        }
         //cout<<arr[5]<<endl;
       
        int mx=0;
        int mx1=0;
        int k=-1;
        int k1=-1;
        for(int i=0;i<=5;i++)
        {
            if(mx<arr[i])
            {
                k=i+1;
                mx=arr[i];
            }
             if(mx1<brr[i])
            {
                k1=i+1;
                mx1=brr[i];
            }
        }
       // cout<<mx<<endl;
       // cout<<k<<" "<<k1<<" ";
        int count=0;
        bool ok=true;
        bool okk =true;
        for(int i=0;i<A.size();i++ )
        {
            if(A[i]!=k)
            {
                if(B[i]==k)
                    count++;
                else
                {
                    ok=false;
                    break;
                }
            }
        }
        
        int count1=0;
          for(int i=0;i<A.size();i++ )
        {
            if(B[i]!=k1)
            {
                if(A[i]==k1)
                    count1++;
                else
                {
                    okk=false;
                    break;
                }
            }
        }
        
       //cout<<count<<" "<<count1<<endl;
        if(!ok&&!okk)
            return -1;
        else if(ok&&okk)
            return min(count,count1);
        else if(ok)
            return count;
        else 
            return count1; 
    }
};