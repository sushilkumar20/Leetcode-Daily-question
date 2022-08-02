class Solution {
public:
    
    int cnt(int mid, vector<vector<int>>& matrix)
    {
        int n=matrix.size();
        int i=0;
        int j =n-1;
        int cnt=0;
        
        while(i<n&&j>=0)
        {
            if(matrix[i][j]>mid)
            {
                j--;
            }
            else
            {
                cnt+=(j+1);
             //   cout<<matrix[i][j]<<" "<<" "<<mid<<" "<<j+1<<endl;
                i++;
            }
            
        }
        
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        
        while(high>low)
        {
            int mid = (low+(high-low)/2);
            
            if(cnt(mid,matrix)>=k)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return low;
            
    }
};