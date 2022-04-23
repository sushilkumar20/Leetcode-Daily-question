class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
         sort(arr2.begin(),arr2.end());
        
        int n=arr1.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            int k = arr1[i]+d;
            int l = arr1[i]-d;
            
            int ind1= lower_bound(arr2.begin(),arr2.end(),l)-arr2.begin();
            
            if(arr2[ind1]==l)
                ind1--;
            int ind2 = upper_bound(arr2.begin(),arr2.end(),k)-arr2.begin();
            
           // cout<<ind1 <<" "<<ind2<<" "<<k<<" "<<l <<endl;
            if(ind1+(arr2.size()-ind2)==arr2.size())
                cnt++;
            
        }
        
        return cnt;
    }
};