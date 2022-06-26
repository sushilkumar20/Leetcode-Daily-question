
class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int ans=0;
        int sum=0;
        for (int i=0;i<k;i++){
            sum += cardPoints[i];
        }
        ans = sum;
        int i=k-1, j= cardPoints.length-1;
        while (i>=0){
            sum -= (cardPoints[i]-cardPoints[j]);
            ans =Math.max(ans, sum);
            i--;
            j--;
        }
        return ans;
    }
}