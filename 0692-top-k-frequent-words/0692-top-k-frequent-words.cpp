class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
       
        sort(words.begin(),words.end());
        
        int freq=1;
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
        
        for(int i=1;i<words.size();i++)
        {
            if(words[i]==words[i-1])
            {
                freq++;
            }
            else
            {
                pq.push({-1*freq,words[i-1]});
                freq=1;
            }
        }
        
        pq.push({-1*freq,words[words.size()-1]});
        
        vector<string>ans;
        for(int i=0;i<k;i++)
        {
           ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};