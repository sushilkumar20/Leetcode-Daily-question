// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string ans="";
  int cnt=0;
  char c;
  for(int i=0;i<src.size();i++)
  {
      if(i==0)
      {
          ans+=src[i];
          c=src[i];
          cnt++;
      }
      else
      {
          if(src[i]==c)
          {
              cnt++;
          }
          else
          {
              ans+=to_string(cnt);
              cnt=1;
              c=src[i];
              ans+=c;
          }
      }
      
  }
  
 
  ans+=to_string(cnt);
  
  return ans;
}     
 
