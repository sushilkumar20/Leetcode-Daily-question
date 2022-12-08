//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
	 
	 class node{
	     public:
	     char val;
	     node *next;
	     node *prv;
	     
	     node(char x)
	     {
	         val = x;
	         next = nullptr;
	         prv = nullptr;
	     }
	 };
		string FirstNonRepeating(string A){
		    // Code here
		    
		    int n = A.size();
		    node *head = new node('#');
		    node *tail = new node('#');
		    
		    head->next = tail;
		    tail->prv = head;
		    
		    vector<int> freq(26,0);
		    vector<node*> pDll(26,nullptr);
		    
		    string ans = "";
		    
		    for(int i=0;i<n;i++)
		    {
		        freq[A[i]-'a']++;
		        
		        if(freq[A[i]-'a']==1)
		        {
		            node *tmp = new node(A[i]);
		            
		            tmp->next = tail;
		            tmp->prv = tail->prv;
		            tail->prv->next = tmp;
		            tail->prv = tmp;
		            
		            pDll[A[i]-'a'] = tmp;
		        }
		        else
		        {
		            node *tmp = pDll[A[i]-'a'];
		            
		            pDll[A[i]-'a'] = nullptr;
		            if(tmp)
		            {
		                tmp->next->prv = tmp->prv;
		                tmp->prv->next = tmp->next;
		                
		            }
		        }
		        
		        ans+=head->next->val;
		    }
		    
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends