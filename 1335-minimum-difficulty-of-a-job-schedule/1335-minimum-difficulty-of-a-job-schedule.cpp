class Solution {
public:
    int solve(int idx, int d, vector<int>& job, vector<vector<int>>& dp){
        if(idx == job.size() && d == 0) return  0;
        if(idx == job.size() || d == 0) return 1e8;
        if(dp[idx][d] != -1) return dp[idx][d];
        int ans = 1e8;
        int cur = 0;
        for(int i=idx;i<job.size();i++){
            cur = max(cur, job[i]);
            int temp = solve(i+1, d-1, job, dp);
            if(temp != 1e8){
                ans = min(ans, cur + temp);
            }
        }
        
        return dp[idx][d] = ans;
    }
    int minDifficulty(vector<int>& job, int d) {
        int n = job.size();
        if(d>n) return -1;
        vector<vector<int>> dp(n, vector<int>(d+1, -1));
        return solve(0, d, job, dp);
    }
};