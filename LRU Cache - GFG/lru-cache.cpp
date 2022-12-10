//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    
    class node
    {
        public:
        int key;
        int value;
        node*next;
        node *prev;
        
        node(int k,int v)
        {
            key=k;
            value=v;
            next=nullptr;
            prev=nullptr;
        }
        
    };
    public:
    //Constructor for initializing the cache capacity with the given value.
    
    map<int,node*> mp;
    node*head;
    node*tail;
    int cp=0;
    LRUCache(int cap)
    {
        // code here
        cp=cap;
        head=new node(0,-1);
        tail = new node(0,-1);
        
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)==mp.end())
        return -1;
        
        
        node *tmp = mp[key];
        
        // erase prev location
        
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        
        mp.erase(key);
        
        tmp->prev=head;
        tmp->next=head->next;
        head->next->prev=tmp;
        head->next=tmp;
        
        mp[key] = tmp;
        
        return tmp->value;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here
        
       
        
        node *nTmp = new node(key,value);
        if(mp.find(key)==mp.end())
        {
             if(mp.size()==cp)
            {
                // cout<<endl;
                //  cout<<key<<" "<<value<<endl;
                node *lru = tail->prev;
                
                lru->next->prev = lru->prev;
                lru->prev->next = lru->next;
                
                mp.erase(lru->key);
            }
            nTmp->prev = head;
            nTmp->next = head->next;
            head->next->prev = nTmp;
            head->next = nTmp;
        }
        else
        {
               node *tmp = mp[key];
        
                // erase prev location
                
                tmp->prev->next = tmp->next;
                tmp->next->prev = tmp->prev;
                
                mp.erase(key);
                
                nTmp->prev = head;
                nTmp->next = head->next;
                head->next->prev = nTmp;
                head->next = nTmp;
        }
        
        
        
        mp[key] = nTmp;
        // cout<<endl;
        //  cout<<mp[key]->value<<endl;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends