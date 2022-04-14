class Solution {
public:
    int maximumSwap(int num) {
        
        string x=to_string(num);
        
        string y=x;
        
        sort(y.rbegin(),y.rend());
        
        int n=x.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(x[i]!=y[i])
            {
                break;
            }
        }
        
        for(int j=n-1;j>=0;j--)
        {
            //cout<<x[j]<<" "<<x[i]<<endl;
            if(x[j]==y[i])
            {
                swap(x[i],x[j]);
                break;
            }
        }
        
       return stoi(x);
    }
};