class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        
        if((m+n)%2)
        {
            int k = (m+n)/2;
            int x=0;
            int i=0;
            int j=0;
            
            while(i<n&&j<m)
            {
                if(nums1[i]<=nums2[j])
                {
                       if(x==k)
                        return nums1[i];
                    x++;
                    i++;
                }
                else
                {
                    if(x==k)
                        return nums2[j];
                    x++;
                    
                    j++;
                }
            }
            
            while(i<n)
            {
                  if(x==k)
                        return nums1[i];
                x++;
               i++;
            }
            
            while(j<m)
            {
                  if(x==k)
                        return nums2[j];
                    x++;
                   
                    j++;
            }
            return x;
        }
        else
        {
            int k = (m+n)/2;
            int p =k-1;
            int x=0;
            double y=0;
            double z=0;
            int i=0;
            int j=0;
            
            while(i<n&&j<m)
            {
                if(nums1[i]<=nums2[j])
                {
                       if(x==k)
                       {
                           y=nums1[i];
                       }
                    if(x==p)
                    {
                        z=nums1[i];
                    }
                    x++;
                    i++;
                }
                else
                {
                     if(x==k)
                       {
                           y=nums2[j];
                       }
                    if(x==p)
                    {
                        z=nums2[j];
                    }
                    x++;
                    
                    j++;
                }
            }
            
            while(i<n)
            {
                   if(x==k)
                       {
                           y=nums1[i];
                       }
                    if(x==p)
                    {
                        z=nums1[i];
                    }
                x++;
               i++;
            }
            
            while(j<m)
            {
                  if(x==k)
                       {
                           y=nums2[j];
                       }
                    if(x==p)
                    {
                        z=nums2[j];
                    }
                    x++;
                   
                    j++;
            }
            return (y+z)/2;
        }
    }
};