class LFUCache {
public:
     class node{
        public:
        int key;
        int value;
        int cnt;
        node * next;
        node * prev;
        node(int _key, int _value)
        {
           key = _key;
           value= _value;
            next=nullptr;
            prev = nullptr;
            cnt = 1;
        }
        
    };
    
    class List{
        public:
        int size;
        node *head;
        node *tail;
        
        List()
        {
            head = new node(-1,-1);
            tail = new node(-1,-1);
            
            head->next = tail;
            tail->prev = head;
            size = 0; 
        }
        
        void addFront(node *Node)
        {
            node *nxt = head->next;
            
            head->next = Node;
            Node->prev = head;
            
            Node->next =  nxt;
            nxt->prev = Node;
            
            size++;
        }
        
        void removeNode(node* Node)
        {
            node *prev = Node->prev;
            node *nxt = Node->next;
            
            prev->next = nxt;
            nxt->prev = prev;
            
            size--;
        }
        
    };
    
    
    map<int,node*> keyNode;
    map<int,List*> freqListMap;
    int cap;
    int mn;
    int currSz = 0; 
    LFUCache(int capacity) {
        cap = capacity;
        mn = 0;
        currSz = 0;
    }
    
    void updateFreqListMap(node *Node)
    {
        keyNode.erase(Node->key);
        
        freqListMap[Node->cnt]->removeNode(Node);
        
        if(Node->cnt == mn && freqListMap[Node->cnt]->size ==0 )
        {
            mn++;
        }
        
        List * nextHigherFreqList = new List();
        
        if(freqListMap.find(Node->cnt+1)!=freqListMap.end())
        {
            nextHigherFreqList = freqListMap[Node->cnt+1];
        }
        
        Node->cnt +=1;
        
        nextHigherFreqList->addFront(Node);
        freqListMap[Node->cnt] = nextHigherFreqList;
        keyNode[Node->key] = Node;
    }
    int get(int key) {
        if(keyNode.find(key) == keyNode.end())
            return -1;
        
       node *temp = keyNode[key];
        
        int value = temp->value;
        updateFreqListMap(temp);
        
        return value;  
        
    }
    
    void put(int key, int value) {
        
        if(cap==0)
            return ;
        if(keyNode.find(key)!=keyNode.end())
        {
          node *temp = keyNode[key];
          temp->value = value;
            
           updateFreqListMap(temp);
        }
        else
        {
            if(currSz == cap)
            {
                List *mnList = freqListMap[mn];
                keyNode.erase(mnList->tail->prev->key);
                freqListMap[mn]->removeNode(mnList->tail->prev);
                currSz--;
            }
            
            currSz++;
            
            mn = 1;
            
            List *nwList = new List();
            
            if(freqListMap.find(mn)!=freqListMap.end())
                nwList = freqListMap[mn];
            
            node* nwNode = new node(key,value);
            
            nwList->addFront(nwNode);
            
            freqListMap[mn] = nwList;
            keyNode[key] = nwNode;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */