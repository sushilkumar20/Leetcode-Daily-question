class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        
        vector<int> brr =arr;
        
        sort(brr.begin(),brr.end());
        
        int st=-1;
        int end=-1;
        for(int i=0;i<brr.size();i++)
        {
            if(arr[i]!=brr[i])
            {
                if(st==-1)
                    st=i;
                end=i;
            }
        }
        
        if(st==-1)
            return 0;
        
        return end-st+1;
    }
};