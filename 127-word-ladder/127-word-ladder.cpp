class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
       vector<bool> arr(wordList.size(),true);
        
        queue<string> q;
        
        q.push(beginWord);
        int cnt=0;
       
        while(!q.empty())
        {
            cnt++;
            int n=q.size();
            for(int x=0;x<n;x++){
            string k=q.front();
            q.pop();
            
           
            if(k==endWord)
            {
                return cnt;
            }
            
             
                
              
              
              for(int i=0;i<wordList.size();i++)
              {
                  string p=wordList[i];
                 
                  if(arr[i]==0)
                      continue;
                   
                  
                 
                 
                  int dif=0;
                  
                  for(int j=0;j<k.size();j++)
                  {
                      if(p[j]!=k[j])
                          dif++;
                  }
                 
                  if(dif==1)
                  {
                     // cout<<p<<" ";
                      q.push(p);
                      arr[i]=0;
                  }
              }
                
                        
        }
            
            
        }
        return 0;
    }
};