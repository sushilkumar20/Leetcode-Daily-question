class Solution {
public:
    static bool cmp(string a,string b)
    {
        string p=a+b;
        string q=b+a;
        
        if(p>q)
            return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        string ans="";
        int n=nums.size();
        vector<string> arr;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(to_string(nums[i]));
        }
        
        sort(arr.begin(),arr.end(),cmp);
        if(arr[0]=="0")
            return "0";
        for(int i=0;i<n;i++)
            ans+=arr[i];
        
        return ans;
    }
};