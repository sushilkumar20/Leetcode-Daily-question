class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
       vector<int> ans;
        
        for(int i=0;i<=k;i++)
        {
            vector<int> a =fun(nums1,i);
            vector<int> b = fun(nums2,k-i);
            
            vector<int> res;
            merge(a,b,res);
            
            if(res.size()==k&&res>ans)
                ans=res;
            
        }
        
        return ans;
    }
    
    vector<int> fun(vector<int> &arr ,int k)
    {
        vector<int> ans;
        int n=arr.size();
        
        for(int i=0;i<n;i++)
        {
            while(ans.size()&&ans.back()<arr[i]&&ans.size()+(n-i)>k)
                ans.pop_back();
            if(ans.size()<k)ans.push_back(arr[i]);
        }
        
        return ans;
    }
    
    void merge(vector<int> &a,vector<int> &b,vector<int> &res)
    {
        int i=0;
        int j=0;
        
        while(i<a.size()&&j<b.size())
        {
            if(a[i]>b[j])
            {
                res.push_back(a[i]);
                i++;
            }
            else if(b[j]>a[i])
            {
                 res.push_back(b[j]);
                j++;
            }
            else
            {
                int x=i;
                int y=j;
                
                while(x<a.size()&&y<b.size()&&a[x]==b[y]){
                    x++;
                    y++;
                }
                
                if(y==b.size())
                {
                    res.push_back(a[i]);
                    i++;
                }
                else if(x<a.size()&&a[x]>b[y])
                {
                    res.push_back(a[i]);
                    i++;
                }
                else
                {
                    res.push_back(b[j]);
                    j++;
                }
            }
        }
        
        while(i<a.size())
        {
             res.push_back(a[i]);
                i++;
        }
        
         while(j<b.size())
        {
             res.push_back(b[j]);
                j++;
        }
        
    }
};