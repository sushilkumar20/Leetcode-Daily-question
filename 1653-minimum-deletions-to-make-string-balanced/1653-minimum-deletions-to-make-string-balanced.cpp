class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        vector<int> temp;
        
        temp.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++)
        {
            if(temp.back()<=nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]+1)-temp.begin();
                
                temp[ind] = nums[i];
            }
        }
        
        return temp.size();
    }
    
    int minimumDeletions(string s) {
        
        int n = s.size();
        
        vector<int> arr(n);
        
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='a')
                arr[i]=0;
            else
                arr[i]=1;
        }
        
        int mx = lengthOfLIS(arr);
        // cout<<mx<<endl;
        
        return s.size()-mx;
    }
};