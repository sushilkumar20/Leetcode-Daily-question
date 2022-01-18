class Solution {
public:
    bool canPlaceFlowers(vector<int>& fl, int n) {
        
       int cnt1=0;
        
        int size=fl.size();
       for(int i=0;i<size;i+=2)
       {
           if(fl[i]==0)
           {
               if(i==0)
               {
                   if(size>=2)
                   {
                       if(fl[i+1]!=1)
                       {
                           cnt1++;
                       }
                   }
                   else
                   {
                       cnt1++;
                   }
               }
               else if(i==size-1)
               {
                   if(size>=2)
                   {
                       if(fl[i-1]!=1)
                       {
                           cnt1++;
                       }
                   }
                   else
                   {
                       cnt1++;
                   }
               }
               else
               {
                   if(fl[i]==0&&fl[i-1]==0&&fl[i+1]==0)
                       cnt1++;
               }
           }
       }
        
        int cnt2=0;
           for(int i=1;i<size;i+=2)
       {
           if(fl[i]==0)
           {
               if(i==0)
               {
                   if(size>=2)
                   {
                       if(fl[i+1]!=1)
                       {
                           cnt2++;
                       }
                   }
                   else
                   {
                       cnt2++;
                   }
               }
               else if(i==size-1)
               {
                   if(size>=2)
                   {
                       if(fl[i-1]!=1)
                       {
                           cnt2++;
                       }
                   }
                   else
                   {
                       cnt1++;
                   }
               }
               else
               {
                   if(fl[i]==0&&fl[i-1]==0&&fl[i+1]==0)
                       cnt2++;
               }
           }
       }
        
        int k=max(cnt1,cnt2);
        
        if(k>=n)
            return true;
        
        return false;
    }
};