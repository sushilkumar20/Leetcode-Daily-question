class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> arr(n,vector<int>(n));
        
        int l=0;
        int r=n-1;
        int t=0;
        int b=n-1;
        
        int x=1;
        int dir=0;
        
       while(l<=r&&t<=b)
       {
           if(dir%4==0)
           {
               for(int i=l;i<=r;i++)
               {
                   arr[t][i]=x;
                   x++;
               }
               t++;
           }
           else if(dir%4==1)
           {
               for(int i=t;i<=b;i++)
               {
                   arr[i][r]=x;
                   x++;
               }
               r--;
           }
            else if(dir%4==2)
           {
               for(int i=r;i>=l;i--)
               {
                   arr[b][i]=x;
                   x++;
               }
                b--;
           }
           else
           {
               for(int i=b;i>=t;i--)
               {
                   arr[i][l]=x;
                       x++;
               }
                l++;
           }
           dir++;
       }
                       
       return arr;
    }
};