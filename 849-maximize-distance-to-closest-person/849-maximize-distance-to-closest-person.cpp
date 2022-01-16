class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        
        int n=seats.size();
        vector<int> p(n);
        vector<int>s(n);
        
        if(seats[0]==1)
        p[0]=0;
        else
            p[0]=1e9;
        for(int i=1;i<n;i++)
        {
            if(seats[i]==1)
            {
                p[i]=0;
            }
            else
            {
                p[i]=1+p[i-1];
            }
        }
        
           if(seats[n-1]==1)
           s[n-1]=0;
           else
            s[n-1]=1e9;
        
        for(int i=n-2;i>=0;i--)
        {
             if(seats[i]==1)
            {
                s[i]=0;
            }
            else
            {
                s[i]=1+s[i+1];
            }
        }
        
        int mx=0;
        
        for(int i=0;i<n;i++)
        {
            //cout<<p[i]<<" "<<s[i]<<endl;
            mx=max(mx,min(p[i],s[i]));
        }
        
        return mx;
    }
};