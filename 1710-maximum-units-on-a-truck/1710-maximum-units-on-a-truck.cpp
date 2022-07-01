class Solution {
public:
    static bool cmp(vector<int> &A, vector<int>&B)
    {
       return A[1]>B[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(),boxTypes.end(),cmp);
        
        int ans = 0;
        
        int currSz =0;
        
        for(int i=0;i<boxTypes.size();i++)
        {
            if(truckSize>=boxTypes[i][0]+currSz)
            {
                currSz+=boxTypes[i][0];
                ans+=boxTypes[i][1]*boxTypes[i][0];
            }
            else
            {
                int rem = truckSize - currSz;
                
                ans+=boxTypes[i][1]*rem;
                break;
            }
        }
        
        return ans;
    }
};