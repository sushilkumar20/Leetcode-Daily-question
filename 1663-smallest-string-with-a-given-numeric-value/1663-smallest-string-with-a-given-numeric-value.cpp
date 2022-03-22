class Solution {
public:
    string getSmallestString(int n, int k) {
        
        vector<int> arr(n,1);
        
        int i=0;
        int j;
        
        int sum=n;
        
        
        while(sum!=k&&i<n)
        {
            j=k-sum;
            
            if(j>=26)
            {
                arr[n-i-1]=26;
                sum+=25;
                i++;
            }
            else
            {
                arr[n-i-1]=j+1;
                sum+=j;
                i++;
            }
        }
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            ans+=(char)(arr[i]-1+'a');
        }
        
        return ans;
    }
};