class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        
       int cnt=0;
        
        int size=fl.size();
        
        for(int i=0;i<size;i++)
        {
            if(fl[i]==0)
            {
                if(i==0)
                {
                    if(i+1<size)
                    {
                    if(fl[i+1]==0)
                    {
                        cnt++;
                        fl[i]=1;
                    }
                    }
                    else
                    {
                        cnt++;
                    }
                    
                }
                else if(i==size-1)
                {
                     if(i-1>=0)
                    {
                    if(fl[i-1]==0)
                    {
                        cnt++;
                        fl[i]=1;
                    }
                     }
                    else
                    {
                        cnt++;
                    }
                }
                else
                {
                    if(fl[i-1]==0&&fl[i+1]==0){
                        fl[i]=1;
                        cnt++;
                    }
                }
            }
        }
        
      
        return cnt>=n;
       
    }
};