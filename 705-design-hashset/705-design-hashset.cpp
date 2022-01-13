class MyHashSet {
public:
    int n=1e6+1;
    vector<int> arr;
    MyHashSet() {
        
        for(int i=0;i<n;i++)
            arr.push_back(0);
    }
    
    void add(int key) {
        arr[key]=1;
    }
    
    void remove(int key) {
        arr[key]=0;
    }
    
    bool contains(int key) {
        return arr[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */