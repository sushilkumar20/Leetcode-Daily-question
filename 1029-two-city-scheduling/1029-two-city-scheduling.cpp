class Solution {
public:
   
    int twoCitySchedCost(vector<vector<int>>& costs) {
          vector<vector<int>> arr;
        
        for(int i=0;i<costs.size();i++)
        {
            vector<int> arr1;
            arr1.push_back(costs[i][0]-costs[i][1]);
             arr1.push_back(costs[i][0]);
             arr1.push_back(costs[i][1]);
            
            arr.push_back(arr1);
        }
        
        sort(arr.begin(),arr.end());
        
        int sum=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(i<arr.size()/2)
            {
                sum+=arr[i][1];
            }
            else
            {
                 sum+=arr[i][2];
            }
        }
        
        return sum;
    }
};