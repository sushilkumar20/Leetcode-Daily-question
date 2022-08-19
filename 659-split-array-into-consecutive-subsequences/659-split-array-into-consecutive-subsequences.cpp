class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        if(nums.size()<3)
        return false;
        map<int,int> freq;
        
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        
        map<int,int> need;
        
        for(int i=0;i<nums.size();i++)
        {
            if(freq[nums[i]]==0)
                continue;
            
            if(need[nums[i]]>0)
            {
               
                need[nums[i]]--;
                freq[nums[i]]--;
                need[nums[i]+1]++;
            }
            else if(freq[nums[i]]>0&&freq[nums[i]+1]>0&&freq[nums[i]+2]>0)
            {
              ///  cout<<nums[i]<<" "<<nums[i]+1<<" "<<nums[i]+2<<endl;
                freq[nums[i]]--;
                freq[nums[i]+1]--;
                freq[nums[i]+2]--;
                
               
                need[nums[i]+3]++;
            }
            else{
                //cout<<i<<endl;
                return false;
            }
        }
        
        return true;
    }
};