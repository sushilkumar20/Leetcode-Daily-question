class LRUCache {
public:
    
   class node{
        public:
        int key;
        int value;
        node * next;
        node * prev;
        node(int _key, int _value)
        {
           key = _key;
           value= _value;
            next=nullptr;
            prev = nullptr;
        }
        
    };
    
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap =0;
    
    map<int,node*> mp;
    
    void addNode(node *temp)
    {
        node *nxt = head->next;
        head->next = temp;
        temp->prev = head;
        nxt->prev = temp;
        temp->next = nxt;
        
    }
    
    void deleteNode(node *temp)
    {
        node *nxt = temp->next;
        node *prev = temp->prev;
        
        nxt->prev = prev;
        prev->next = nxt;
        
       // delete(temp);
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end())
            return -1;
        else
        {
            node *res = mp[key];
            int value = res->value;
            
            deleteNode(res);
            addNode(res);
            
            mp[key] = head->next;
            return value;
        }
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
             node *res = mp[key];
             
            
            deleteNode(res);
            res->value = value;
            addNode(res);
            
            mp[key] = head->next;
        }
        else
        {
            if(mp.size()==cap)
            {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            
            addNode(new node(key,value));
            mp[key] = head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */