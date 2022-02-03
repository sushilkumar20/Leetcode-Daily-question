class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int cnt=0;
        
      map<int,int>mp;
        
        for(int i=0;i<nums3.size();i++)
        {
            for(int j=0;j<nums4.size();j++)
                mp[nums3[i]+nums4[j]]++;
        }
        
       //sort(nums4.begin(),nums4.end());
        
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                int p=nums1[i]+nums2[j];
               cnt+=mp[0-p];
            }
        }
        
        return cnt;
    }
};