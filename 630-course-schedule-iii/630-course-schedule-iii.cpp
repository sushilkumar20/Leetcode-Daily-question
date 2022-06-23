class Solution {
public:
    static bool cmp(vector<int> &A,vector<int> &B){
        return A[1]<B[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        
        int n=courses.size();
        sort(courses.begin(),courses.end(),cmp);
        
        priority_queue<int> pq;
        
        
        int curr=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(curr+courses[i][0]<=courses[i][1]){
                cnt++;
                curr+=courses[i][0];
                pq.push(courses[i][0]);
            }
            else if(pq.size()&&pq.top()>=courses[i][0])
            {
                curr-=pq.top();
                pq.pop();
                curr+=courses[i][0];
                pq.push(courses[i][0]);
            }
        }
        
        return cnt;
    }
};