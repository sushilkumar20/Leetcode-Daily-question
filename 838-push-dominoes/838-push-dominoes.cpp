class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n=dominoes.size();
        vector<int> left(n);
        vector<int> right(n);
        
        int l=n;
        for(int i=n-1;i>=0;i--)
        {
            if(dominoes[i]=='R')
            {
                l=n;
                left[i]=n;
            }
            else if(dominoes[i]=='L')
            {
                l=i;
                left[i]=0;
            }
            else if(l==n)
            {
                left[i]=n;
            }else
            {
                left[i]=l-i;
            }
        }
        
        int r=n;
         for(int i=0;i<n;i++)
        {
            if(dominoes[i]=='L')
            {
                r=n;
                right[i]=n;
            }
            else if(dominoes[i]=='R')
            {
                r=i;
                right[i]=0;
            }
            else if(r==n)
            {
                right[i]=n;
            }else
            {
                right[i]=i-r;
            }
        }
        
        string ans="";
        
        for(int i=0;i<n;i++)
        {
            if(left[i]==right[i])
                ans+=".";
            else if(left[i]<right[i])
                ans+='L';
            else
                ans+='R';
        }
        
        return ans;
    }
};