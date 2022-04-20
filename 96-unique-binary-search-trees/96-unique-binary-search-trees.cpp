class Solution {
public:
    int catalan(int n){
        vector<int> arr(n+2,0);
        
        arr[0]=1;
        arr[1]=1;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<i;j++)
                arr[i]+= arr[j]*arr[i-j-1];
        }
        return arr[n];
        
    }
    int numTrees(int n) {
        return catalan(n);
    }
};