class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& a) {
        
        int n=a.size(),ans=0;
        for(int i=0;i<n;i++)a[i][1]*=-1;
        sort(a.begin(),a.end());
        int ma=-1;
        for(int i=n-1;i>=0;i--){
            if(-a[i][1]<ma)ans++;
            ma=max(ma,-a[i][1]);
        }
        return ans;
    }
};