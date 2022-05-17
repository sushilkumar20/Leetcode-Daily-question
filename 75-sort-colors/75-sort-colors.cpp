class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0;
        int curr = 0;
        int high = n-1;
        
        while(curr<=high)
        {
            if(nums[curr]==0)
            {
               // cout<<curr<<endl;
                swap(nums[curr],nums[low]);
                low++;
                curr++;
            }
            else if(nums[curr]==1)
            {
               // cout<<curr<<endl;
                curr++;
            }
            else 
            {
                
                swap(nums[curr],nums[high]);
                high--;
                
               
                    
            }
        }
    }
};