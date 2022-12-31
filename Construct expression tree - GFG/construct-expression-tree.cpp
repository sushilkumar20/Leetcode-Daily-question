//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct et
{
	char value;
	et* left, *right;
	
	et(char x){
	    value = x;
	    left = right = NULL;
	}
};

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

void inorder(et *t)
{
	if(t)
	{
		inorder(t->left);
		printf("%c ", t->value);
		inorder(t->right);
	}
}

et* constructTree(char []);

int main()
{   
    int t;
    cin>>t;
    while(t--){
    char postfix[25];
	cin>>postfix;
	et* r = constructTree(postfix);
	inorder(r);
	cout<<endl;
}
return 0;
}
// } Driver Code Ends


/*struct et
{
	char value;
	et* left, *right;
};*/

//function to construct expression tree
et*help( string &s, int i, int j)
{
    if(i<=j)
    {
        et *tmp = new et('@');
        
        tmp->left= nullptr;
        tmp->right =  nullptr;
        for(int x=i;x<=j;x++)
        {
            if(isOperator(s[x]))
            {
                tmp->value = s[x];
                tmp->left = help(s,i,x-1);
                tmp->right = help(s,x+1,j);
                return tmp;
            }
        }
        
        tmp->value = s[i];
        return tmp;
    }
}
et* constructTree(char postfix[])
{
//code here
     stack<et*>st;
     
     for(int i=0;postfix[i]!='\0';i++)
     {
         if(isOperator(postfix[i]))
         {
             et*right = st.top();
             st.pop();
             et*left = st.top();
             st.pop();
             
             et *node = new et(postfix[i]);
             node->left = left;
             node->right=right;
             st.push(node);
         }
         else
         {
             et *node = new et(postfix[i]);
             st.push(node);
         }
     }
     
     return st.top();
}
