class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int mx = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(i<n-1&&(mx-1==0||mx==0)&&nums[i]==0)
                return false;
            
            mx = max(mx-1,nums[i]);
            //cout<<mx<<" "<<i<<endl;
        }
        
        return true;
    }
};