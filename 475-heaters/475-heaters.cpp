class Solution {
public:
    bool pos(int r, vector<int>&heaters, vector<int>& houses)
    {
        int i=0;
        int j=0;
        
        int m=heaters.size();
        int n=houses.size();
        while(j<m)
        {
            if(i>=n)
                return true;
            while(i<n)
            {
                if(houses[i]>=heaters[j]-r&&houses[i]<=heaters[j]+r)
                    i++;
                else
                    break;
            }
            j++;
        }
        
        if(i>=n)
            return true;
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int low = 0;
        int high = 1e9;
    
        while(low<high)
        {
            int  mid = (low+high)/2;
            
            if(pos(mid,heaters,houses))
            {
                high=mid;
            }
            else
                low=mid+1;
        }
        
        return low;
    }
};