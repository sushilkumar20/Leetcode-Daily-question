class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        int n=nums.size();
        vector<int> arr1;
        vector<int> arr2;
        vector<int> arr3;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot)
                arr3.push_back(nums[i]);
            else if(nums[i]<pivot)
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        
        int i=0;
        
        for(int j=0;j<arr1.size();j++)
        {
            nums[i] =arr1[j];
            i++;
        }
        
         for(int j=0;j<arr2.size();j++)
        {
            nums[i] =arr2[j];
            i++;
        }
        
         for(int j=0;j<arr3.size();j++)
        {
            nums[i] =arr3[j];
            i++;
        }
        
        return nums;
    }
};